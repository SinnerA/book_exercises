#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>

#define MAX_EVENT_NUMBER 1024
static int pipefd[2];

int setnonblocking(int fd){
	int old_option = fcntl(fd, F_GETFL);
	int new_option = old_option | O_NONBLOCK;
	fcntl(fd, F_SETFL, new_option);
	return old_option;
}

void addfd(int epollfd, int fd){
	epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN | EPOLLET;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
	setnonblocking(fd);
}

/*信号处理函数*/
void sig_handler(int sig){
	int save_errno = errno;
	int msg = sig;
	ret = send(pipefd[1], (char *)msg, 1, 0); //将信号写入管道，通知主循环
	errno = save_errno;
}

/*设置信号的处理函数*/
void addsig(int sig){
	struct sigaction sa;
	memset(&sa, '\0', sizeof(sa));
	sa.sa_handler = sig_handler;
	sa.sa_falgs |= SA_RESTART;
	sigfillset(&sa.sa_mask); //执行信号处理函数期间，屏蔽所有信号
	assert((sigaction(sig, &sa, NULL) != -1));
}

int mian(int argc, char *argv[]){
	if(argc <= 2){
		printf("usage: %s ip_address port_number\n", basename(argv[0]));
		return 1;
	}
	const char* ip = argv[1];
	int port = atoi(argv[2]);
	
	struct sockaddr_in address;
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);
	address.sin_port = htons(port);
	
	int listenfd = socket(PF_INET, SOCK_STREAM, 0);
	assert(listenfd >= 0);
	
	int ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
	assert(ret != -1);

	ret = listen(listenfd, 5);
	assert(ret != -1);
	
	epoll_event events[MAX_EVENT_NUMBER];
	int epollfd = epoll_create(5);
	assert(epollfd != -1);
	addfd(epollfd, listenfd);
	
	/*建立Unix域套接字（全双工），用于信号处理函数与主循环之间的通信*/
	ret = socketpair(PF_UNIX, SOCK_STREAM, 0, pipefd);
	assert(ret != -1);
	setnonblocking(pipefd[1]);
	addfd(epollfd, pipefd[0]);
	
	/*设置一些信号的处理函数*/
	addsig(SIGHUP);
	addsig(SIGTERM);
	addsig(SIGINT);
	addsig(SIGCHLD);
	bool stop_server = false;
	
	while(!stop_server){
		int number = epoll_wait(epollfd, &events, MAX_EVENT_NUMBER, -1);
		if(number < 0 && errno != EINTR){
			printf("epoll failed\n");
			break;
		}
		for(int i = 0; i < number; i++){
			int sockfd = events[i].data.fd;
			if(sockfd == listenfd){
				struct sockaddr_in client_address;
				socklen_t client_addrlength = sizeof(client_address);
				int connfd = accept(sockfd, (struct sockaddr*)&client_address, &client_addrlength);
				assert(connfd >= 0);
				addfd(epollfd, connfd);
			} else if((sockfd == pipefd[0]) && (events[i].events & EPOLLIN)){
				char signals[1024];
				memset(signals, '\0', 1024);
				ret = recv(sockfd, signals, sizeof(signals), 0);
				if(ret < 0){
					continue;
				} else if(ret == 0){
					continue;
				} else {
					for(int i = 0; i < ret; i++){
						switch (signals[i]){
							case SIGHUP:
							case SIGCHLD:
								continue;
							case SIGTERM:
							case SIGINT:
								stop_server = true;
						}
					}
				}
			}
		}
	}
	printf("close fds\n");
	close(listenfd);
	close(pipefd[1]);
	close(pipefd[0]);
	return 0;
}