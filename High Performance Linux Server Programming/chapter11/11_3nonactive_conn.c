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
#include "11_2lst_timer.h"

#define FD_LIMIT 65535
#define MAX_EVENT_NUMBER 1024
#define TIMESLOT 5

static int pipefd[2];
static sort_timer_lst timer_lst; //升序链表管理定时器
static int epollfd = 0;

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

void sig_handler(int sig){
	int save_errno = errno;
	int msg = sig;
	send(pipefd[1], (char *)msg, 1, 0);
	errno = save_errno;
}

void addsig(int sig){
	struct sigaction sa;
	memset(&sa, '\0', sizeof(sa));
	sa.sa_handler = sig_handler;
	sa.sa_flags |= SA_RESTART;
	sigfillset(&sa.sa_mask);
	assert(sigaction(sig, &sa, NULL) != -1);
}

void timer_handler(){
	/*定时处理任务：删除到期定时器并执行回调函数*/
	timer_lst.tick();
	/*因为一次alarm调用只会引起一次SIGALARM信号，所以要重新定时，以不断触发SIGALARM信号*/
	alarm(TIMESLOT);
}

/*定时器回调函数，删除非活动连接socket上的注册事件，并关闭此socket*/
void cb_func(client_data* user_data){
	epoll_ctl(epollfd, EPOLL_CTL_DEL, user_data->sockfd, 0);
	assert(user_data);
	close(user_data->sockfd);
	printf("close fd %d\n", user_data->sockfd);
}

int main(int argc, char *argv[]){
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
	assert(epollfd != 0);
	addfd(epollfd, listenfd);
	
	ret = socketpair(PF_UNIX, SOCK_STREAM, 0, pipefd);
	assert(ret != -1);
	setnonblocking(pipefd[1]);
	addfd(epollfd, pipefd[0]);
	
	/*设置信号处理函数*/
	addsig(SIGALARM);
	addsig(SIGTERM);
	bool stop_server = false;
	
	client_data* users = new client_data[FD_LIMIT];
	bool timeout = false;
	alarm(TIMESLOT); /*定时*/
	
	while(!stop_server){
		int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
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
				addfd(epollfd, connfd);
				
				users[connfd].address = client_address;
				users[connfd].sockfd = connfd;
				util_timer* timer = new util_timer;
				timer->client_data = users[connfd];
				timer->cb_func = cb_func;
				time_t cur = time(NULL);
				timer->expire = cur + 3*TIMESLOT;
				users[connfd].timer = timer;
				timer_lst.add_timer(timer);
			} else if((sockfd == pipefd[0]) && (events[i].events & EPOLLIN)){
				char signals[1024];
				memset(signals, '\0', sizeof(signals));
				ret = recv(pipefd[0], signals, sizeof(signals), 0);
				if(ret < 0){
					//handle the error
					continue;
				} else if(ret == 0){
					continue;
				} else {
					for(int i = 0; i < ret; i++){
					switch (signals[i])
						case SIGALARM:
							/*关闭长时间不响应的连接*/
							timeout = true;//不立即处理定时任务
							break;
						case SIGTERM:
							stop_server = true;
					}
				}
			} else if(events[i].events & EPOLLIN){
				memset(users[sockfd].buf, '\0', BUFFER_SIZE);
				ret = recv(sockfd, users[sockfd].buf, BUFFER_SIZE - 1， 0);
				
				util_timer* timer = users[sockfd].timer;
				if(ret < 0){
					if(errno != EAGAIN){
						/*发生错误，则关闭连接，并移除定时器*/
						cb_func(&users[sockfd]);
						if(timer){
							timer_lst.del_timer(timer);
						}
					}
				} else if(ret == 0){
					/*对方已关闭连接，则关闭连接，并移除定时器*/
					cb_func(&users[sockfd]);
					if(timer){
						timer_lst.del_timer(timer);
					}
				} else {
					printf("get %d bytes of client data %s from %d\n", ret, users[sockfd].buf, sockfd);
					/*有数据，则需要调整定时器，以延迟该连接被关闭的时间*/
					if(timer){
						time_t cur = time(NULL);
						timer->expire = cur + 3*TIMESLOT;
						printf("adjust timer once\n");
						timer_lst.adjust_timer(timer);
					}
				}
			} else {
				//others
			}
		}
		/*最后处理定时事件*/
		if(timeout){
			timer_handler();
			timeout = false;
		}
	}
	close(listenfd);
	close(pipefd[0]);
	close(pipefd[1]);
	delete[] users;
	return 0;
}