#define _GNU_SOURCE 1
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
#include <poll.h>

#define USER_LIMIT 5   //最大用户数量
#define BUFFER_SIZE 64 //读缓冲区大小
#define FD_LIMIT 65535 //文件描述符数量限制

/*客户数据*/
struct client_data{
	struct sockaddr_in address;
	char* write_buf;       //待写到客户端的数据的位置
	char buf[BUFFER_SIZE]; //从客户端读入的数据
};

/*设为非阻塞*/
int setnonblocking(int fd){
	int old_option = fcntl(fd, F_GETFL);
	int new_option = ole_option | O_NONBLOCK;
	fcntl(fd, F_SETFL, new_option);
	return old_option;
}

int main(int agrc, char *argv[]){
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
	
	int listenfd = sock(PF_INET, SOCK_STREAM, 0);
	assert(listenfd >= 0);
	
	int ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
	assert(ret != -1);
	
	ret = listen(listenfd, 5);
	assert(ret != -1);
	
	client_data* users = new client_data[FD_LIMIT]; //可以直接用sockfd索引客户信息
	pollfd fds[USER_LIMIT + 1];                     //限制用户数量
	fds[0].fd = listenfd;
	fds[0].events = POLLIN | POLLERR;
	fds[0].revents = 0;
	for(int i = 1; i <= USER_LIMIT; i++){
		fds[i].fd = -1;
		fds[i].events = 0;
	}
	
	int user_counter = 0;
	while(1){
		ret = poll(fds, user_counter + 1, -1); //user_counter为sockfd数量，1为listenfd
		if(ret < 0){
			printf("poll failed\n");
			break;
		}
		for(int i = 0; i < user_counter + 1; i++){
			if((fds[i].fd == listenfd) && (fds[i].revents & POLLIN)){
				struct sockaddr_in client_address;
				socklen_t clientaddr_length = sizeof(client_address);
				int connfd = accept(listenfd, (struct sockaddr*)&client_address, &clientaddr_length);
				if(connfd < 0){
					printf("errno is: %d\n", errno);
					continue;
				}
				/*如果请求太多，关闭新到的连接*/
				if(user_counter >= USER_LIMIT){
					const char* info = "too many users\n";
					printf("%s", info);
					send(connfd, info, strlen(info), 0);
					close(connfd);
				}
				user_counter++;
				users[connfd].address = client_address;
				setnonblocking(connfd);
				fds[i].fd = connfd;
				fds[i].events = POLLIN | POLLERR | POLLRDHUP;
				fds[i].revents = 0;
				printf("comes a new user, now have %d users\n", user_counter);
			} else if(fds[i].revents & POLLERR){
				printf("get an error from %d\n", fds[i].fd);
				char error[100];
				memset(error, '\0', sizeof(error));
				socklen_t errlength = sizeof(error);
				if(getsockopt(SOL_SOCKET, SO_ERROR, &error, &errlength) < 0){
					printf("get socket option failed\n");
				}
				continue;
			} else if(fds[i].revents & POLLRDHUP){
				/*客户端已关闭连接，则服务器也关闭连接，并将用户数减1*/
				users[fds[i].fd] = users[fds[user_counter].fd];
				close(fds[i].fd);
				fds[i] = fds[user_counter];
				user_counter--;
				i--; //将已加1的i恢复
			} else if(fds[i].revents & POLLIN){
				int connfd = fds[i].fd;
				ret = recv(connfd, users[connfd].buf, BUFFER_SIZE - 1, 0);
				if(ret < 0){
					//操作出错，关闭连接
					if(errno != EAGAIN){
						close(connfd);
						users[connfd] = users[fds[user_counter].fd];
						fds[i] = fds[user_counter];
						user_counter--;
						i--;
					}
				} else if(ret == 0){
					
				} else {
					printf("get %d bytes of client data %s from %d\n", ret, users[connfd].buf, connfd);					
					/*接收到数据，则通知其他sockfd写数据，即将其数据转发给其他客户*/
					for(int j = 1; j <= user_counter; j++){
						if(fds[j].fd == connfd) continue;
						users[fds[j].fd].write_buf = users[connfd].buf;
						fds[j].events |= ~POLLIN;
						fds[j].enents |= POLLOUT;
					}
				}
			} else if(fds[i].revents & POLLOUT){
				int connfd = fds[i].fd;
				if(!users[connfd].write_buf) continue;
				send(connfd, users[connfd].write_buf, sizeof(users[connfd].write_buf), 0);
				users[connfd].write_buf = NULL;
				/*写完数据后，重新注册可读事件*/
				fds[i].events |= ~POLLOUT;
				fds[i].events |= POLLIN;
			}
		}
	}
	delete[] users;
	close(listenfd);
	return 0;
}