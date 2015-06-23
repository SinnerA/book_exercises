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
#include <signal.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define USER_LIMIT 15
#define BUFFER_SIZE 1024
#define FD_LIMIT 65536
#define MAX_EVENT_NUMBER 1024
#define PROCESS_LIMIT 65536

/*处理客户连接的必要数据*/
struct client_data{
	struct sockaddr_in address; /*客户端的socket地址*/
	int connfd;                 /*socket文件描述符*/
	pid_t pid;                  /*处理这个连接的子进程*/
	int pipefd[2];              /*和父进程通信的管道*/
};

/*全局变量-------------------------------------------------------------*/
static const char* shm_name = "/my_shm";
int sig_pipefd[2];
int epollfd;
int listenfd;
int shmfd;
char *share_mem = 0;
client_data *users = 0; /*客户连接数据*/
int *sub_process = 0;   /*子进程与客户连接的映射关系表*/
int user_counts = 0;    /*当前客户数量*/
bool stop_child = false;

int setnonblocking(int fd){
	int old_option = fctl(fd, F_GETFL);
	int new_option = old_option | O_NONBLOCK;
	fcntl(fd, F_SETFL, new_option);
	return new_option;
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
	send(sig_pipefd[1], (char*)&msg, 1, 0);
	errno = save_errno;
}

void addsig(int sig, void(*handler)(int), bool is_restart = true){
	struct sigaction sa;
	memset(&sa, '\0', sizeof(sa));
	sa.sa_handler = handler;
	if(is_restart){
		sa.sa_flags |= SA_RESTART;
	}
	sigfillset(&sa.sa_mask);
	assert(sigaction(sig, &sa, NULL) != -1);
}

void del_source(){
	close(sig_pipefd[0]);
	close(sig_pipefd[1]);
	close(listenfd);
	close(epollfd);
	shm_unlink(shm_name);
	delete[] users;
	delete[] sub_process;
}

void child_term_handler(int sig){
	stop_child = true;
}

/*运行子进程-----------------------------------------------------------*/
int run_child(int idx, client_data* user, char* share_mem){
	epoll_event events[MAX_EVENT_NUMBER];
	int child_epollfd = epoll_create(5);
	assert(child_epollfd != -1);
	
	int connfd = user[idx].connfd;
	addfd(child_epollfd, connfd);
	int pipefd = user[idx].pipefd[1];
	addfd(child_epollfd, pipefd);
	addsig(SIGTERM, child_term_handler, false);
	
	int ret;
	
	while(!stop_child){
		/*子进程监听两个描述符：客户连接connfd，与父进程通信pipefd[0]*/
		int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
		if(number < 0 && errno != EINTR){
			printf("epoll failed\n");
			break;
		}
		for(int i = 0; i < number; i++){
			int sockfd = events[i].data.fd;
			/*1：客户数据*/
			if(sockfd == connfd){
				/*将客户数据读取到共享内存对应的位置*/
				char* buf = share_mem + idx*BUFFER_SZIE;
				memset(buf, '\0', BUFFER_SIZE);
				ret = recv(sockfd, buf, BUFFER_SIZE - 1, 0);
				if(ret < 0 && errno != EAGAIN){
					//发生错误
					stop_child = true;
				} else if(ret == 0){
					//对端已关闭
					stop_child = true;
				} else {
					/*因为使用共享内存，则父进程只需要知道idx，便可以得到此次接受的客户数据*/
					send(pipefd, (char*)&idx, sizeof(idx), 0);
				}
			} 
			/*2：父进程数据*/
			else if((sockfd == pipefd) && (events[i].events & EPOLLIN)){
				int cilent = 0;/*只是一个客户编号*/
				ret = recv(sockfd, (char*)&client, sizeof(client), 0);
				if(ret < 0 && errno != EAGAIN){
					stop_child = true;
				} else if(ret == 0){
					stop_child = true;
				} ele {
					char* buf = share_mem + client*BUFFER_SIZE;
					send(connfd, buf, BUFFER_SIZE, 0);
				}
			} else {
				continue;
			}
		}
	}
	close(connfd);
	close(pipefd);
	close(child_epollfd);
	return 0;
}

/*主函数---------------------------------------------------------------*/
int main(int argc, char *argv[]){
	if(argc <= 2){
		printf("usage: %s ip_address port_number\n");
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
	
	user_count = 0;
	users = new client_data[USER_LIMIT + 1];
	sub_process = new int[PROCESS_LIMIT];
	for(int i = 0; i < PROCESS_LIMIT; i++)
		sub_process[i] = -1;
	
	epoll_event events[MAX_EVENT_NUMBER];
	epollfd = epoll_create(5);
	assert(epollfd != -1);
	addfd(epollfd, listenfd);
	
	ret = socketpair(PF_UNIX, SOCK_STREAM, 0, sig_pipefd);
	assert(ret != -1);
	setnonblocking(sig_pipefd[1]);
	addfd(epollfd, sig_pipefd[0]);
	
	addsig(SIGCHLD, sig_handler);
	addsig(SIGTERM, sig_handler);
	addsig(SIGINT, sig_handler);
	addsig(SIGPIPE, SIG_IGN);
	bool stop_server = false;
	bool terminate = false;
	
	/*创建共享内存，作为所有客户socket连接的读缓存*/
	shmfd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
	assert(shmfd != -1);
	ret = ftruncate(shmfd, USER_LIMIT * BUFFER_SIZE);
	assert(ret != -1);
	
	share_mem = (char*)mmap(NULL, USER_LIMIT * BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
	assert(share_mem != MAP_FAILED);
	close(shmfd);
	
	while(!stop_server){
		number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
		if(number < 0 && errno != ENITR){
			printf("epoll failed\n");
			break;
		}
		for(int i = 0; i < number; i++){
			int sockfd = events[i].data.fd;
			/*1：新的客户到来*/
			if(sockfd == listenfd){
				struct sockaddr_in client_address;
				socklen_t client_addrlength = sizeof(client_address);
				int connfd = accept(sockfd, (sock_addr*)&client_address, &client_addrlength);
				addfd(epollfd, connfd);
				if(connfd < 0){
					printf("error is %d\n", errno);
					continue;
				}
				if(user_count >= USER_LIMIT){
					const char* info = "too many users\n";
					printf("%s", info);
					send(connfd, info, sizeof(info), 0);
					close(connfd);
					continue;
				}
				/*保存用户数据*/
				users[user_count].address = client_address;
				users[user_count].connfd = connfd;
				/*建立管道，用于父子进程间通信*/
				ret = socketpair(PF_UNIX, SOCK_STREAM, 0, users[user_count].pipefd);
				assert(ret != -1);
				
				pid_t pid = fork();
				if(pid < 0){
					close(connfd);
					break;
				} else if(pid == 0){
					close(listenfd);
					close(epollfd);
					close(users[user_count].pipefd[0]);
					close(sig_pipefd[0]);
					close(sig_pipefd[1]);
					run_child(user_count, users, share_mem);
					munmap((void*)share_mem, USER_LIMIT * BUFFER_SIZE);/*子进程结束，解除内存映射（每个子进程中都有一份映射）*/
					exit(0);
				} else {
					close(connfd);
					close(users[user_count].pipefd[1]);
					addfd(epollfd, users[user_count].pipefd[0]);
					sub_process[pid] = user_count;
					users[user_count].pid = pid;
					user_count++;
				}
			}
			/*2：处理信号事件*/
			else if((sockfd == sig_pipefd[0]) && (events[i].events & EPOLLIN)){
				char signals[1024];
				ret = recv(sig_pipefd[0], signals, sizeof(signals), 0);
				if(ret <= 0){
					continue;
				} else {
					for(int i = 0; i < ret; i++){
						switch(signals[i]){
							/*子进程退出，表示某个客户端关闭了连接*/
							case SIGCHLD:
							{
								pid_t pid;
								int stat;
								while((pid = wait_pid(-1, &stat, WNOHANG)) > 0){
									/*取得客户编号*/
									int del_user = sub_process[pid];
									sub_process[pid] = -1;
									if(del_user < 0 || del_uer > USER_LIMIT){
										continue;
									}
									/*删除相关数据*/
									epoll_ctl(epollfd, EPOLL_CTL_DEL, users[del_user].pipefd[0], 0);
									close(users[del_user].pipefd[0]);
									users[del_user] = users[--user_count];
									sub_process[users[del_user].pid] = del_user;
								}
								if(terminate && user_count == 0){
									stop_server = true;
								}
								break;
							}
							case SIGTERM:
							/*结束服务器程序*/
							case SIGINT:
							{
								printf("kill all the child now\n");
								if(user_count == 0){
									stop_server = true;
									break;
								}
								for(int i = 0; i < user_count; i++){
									int pid = users[i].pid;
									kill(pid, SIGTERM);
								}
								terminate = true;
								break;
							}
							default:
								break;
						}
					}
				}
			/*3：子进程数据*/
			} else if(events[i].events & EPOLLIN){
				int child = 0;
				ret = recv(sockfd, (char*)&child, sizeof(child), 0);
				if(ret <= 0){
					continue;
				} else{
					/*向除本子进程外的其他子进程发送消息，通知有客户数据要写*/
					for(int j = 0; j < user_count; j++){
						if(users[j].pipefd[0] != sockfd){
							printf("send data to child accross pipe\n");
							send(users[j].pipefd[0], (char*)&child, sizeof(child), 0);
						}
					}
				}
			}
		}
	}
	del_resource();
	return 0;
}