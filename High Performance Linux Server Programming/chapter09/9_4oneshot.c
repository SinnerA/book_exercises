#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>

#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 1024

struct fds{
	int epollfd;
	int sockfd;
};

/*设为非阻塞*/
int setnonblocking(int fd){
	int old_option = fcntl(fd, F_GETFL);
	int new_option = old_option | O_NONBLOCK;
	fcntl(fd, F_SETFL, new_option);
	return old_option;
}

/*注册事件*/
void addfd(int epollfd, int sockfd, bool oneshot){
	epoll_event event;
	event.data.fd = sockfd;
	event.events = EPOLLIN | EPOLLET;
	if(oneshot){
		event.events |= EPOLLONESHOT;
	}
	epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &event);
	setnonblocking(sockfd);
}

/*重置sockfd上的事件，确保下一次可读时，EPOLLIN能被触发*/
void resetoneshot(int epollfd, int sockfd){
	epoll_event event;
	event.data.fd = sockfd;
	event.events = EPOLLIN | EPOLLET | EPOLLONESHOT;
	epoll_ctl(epollfd, EPOLL_CTL_MOD, sockfd, &event);
}

/*工作线程*/
void *work(void *arg){
	int sockfd = (fd*(arg))->sockfd;
	int epollfd = (fd*(arg))->epollfd;
	
	printf("start new thread to receve the data on fd: %d\n", sockfd);
	char buf[BUFFER_SIZE];
	memset(buf, '\0', BUFFER_SIZE);
	/*ET模式，循环读取，直到遇到EAGAIN*/
	while(1){
		int ret = recv(sockfd, buf, BUFFER_SIZE - 1, 0);
		if(ret < 0){
			if(errno == EAGAIN || errno == EWOULDBLOCK){
				resetoneshot(epollfd, sockfd);
				printf("read later\n");
				break;
			}
		} else if(ret == 0){
			close(sockfd);
			printf("foriner closed the connection\n");
			break;
		} else {
			printf("get content: %s\n", buf);
			/*休眠5s，模拟数据处理过程*/
			sleep(5);
		}
	}
	printf("end thread receving data on fd: %d\n", sockfd);
}

int main(int argc, char* argv[]){
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
	
	int listenfd = sockfd(PF_INET, SOCK_STREAM, 0);
	assert(listenfd >= 0);
	
	int ret = 0;
	ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
	assert(ret != -1);
	
	ret = listen(listenfd, 5);
	assert(ret != -1);
	
	epoll_event events[MAX_EVENT_NUMBER];
	int epollfd = epoll_create(5);
	assert(epollfd != -1);
	addfd(epollfd, listenfd, false);
	
	while(1){
		ret = epoll_wait(epollfd, &events, MAX_EVENT_NUMBER, -1);
		if(ret < 0){
			printf("epoll failure\n");
			continue;
		}
		for(int i = 0; i < ret; i++){
			int sockfd = events[i].data.fd;
			if(sockfd == listenfd){
				struct sockaddr_in client_address;
				socklen_t client_addrlength = sizeof(client_address);
				int connfd = accept(listenfd, (struct sockaddr*)&client_address, &client_addrlength);
				/*对每个非监听描述符都注册EPOLLONESHOT事件*/
				addfd(epollfd, connfd, true);
			} else if(events[i].events & EPOLLIN) {
				pthread_t thread;
				fds fds_for_new_worker;
				fds_for_new_worker.sockfd = sockfd;
				fds_for_new_worker.epollfd = epollfd;
				/*启动一个新线程为sockfd服务*/
				pthread_create(&thread, NULL, worker, (void *)&fds_for_new_worker);
			} else {
				printf("something else happened\n");
			}
		}
	}
	close(listenfd);
	return 0;
}