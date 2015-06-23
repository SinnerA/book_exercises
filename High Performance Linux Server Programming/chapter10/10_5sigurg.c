#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
static int connfd;

/*SIGURG信号的处理函数*/
void sig_urg(int sig){
	int save_errno = errno;
	char buf[BUFFER_SIZE];
	memset(buf, '\0', BUFFER_SIZE);
	int ret = recv(connfd, buf, BUFFER_SIZE - 1, MSG_OOB);
	printf("got %d bytes of oob data '%s'\n", ret, buf);
	errno = save_errno;
}

/*设置信号的处理函数*/
void addsig(int sig, void (*sig_handler)(int)){
	struct sigaction sa;
	sa.sa_handler = sig_handler;
	sa.sa_falgs |= SA_RESTART;
	sigfillset(&sa.sa_mask);
	assert(sigaction(sig, &sa, NULL) != -1);
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
	
	int listenfd = socket(PF_INET, SOCK_STREAM, 0);
	assert(listenfd >= 0);
	
	int ret = bind(listenfd, (struct sockaddr*)&address, sizeof(address));
	assert(ret != -1);
	
	ret = listen(listenfd, 5);
	assert(ret != -1);
	
	struct sockaddr_in client_address;
	socklen_t client_addrlength = sizeof(client_address);
	connfd = accept(listenfd, (struct sockaddr*)&client_address, &client_addrlength);
	if(connfd < 0){
		printf("errno is : %d\n", errno);
	} else {
		addsig(SIGURG, sig_urg);
		/*使用SIGURG之前，必须重置socket的宿主进程或进程组*/
		fcntl(connfd, F_SETOWM, getpid());
		char buf[BUFFER_SIZE];
		while(1){
			/*接受普通数据*/
			memset(buf, '\0', BUFFER_SIZE);
			ret = recv(connfd, buf, BUFFER_SIZE - 1, 0);
			if(ret <= 0){
				break;
			}
			printf("got %d bytes of normal data: %s\n", ret, buf);
		}
		close(connfd);
	}
	close(listenfd);
	return 0;
}