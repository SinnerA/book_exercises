#include <sys/type.h>
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

int main(int argc, char* argv[]){
	if(argc <= 2){
		printf("usage: %s ip_address port_number\n", basename(argv[0]));
		return 1;
	}
	const char* ip = argv[0];
	int port = atoi(argv[1]);
	
	int ret = 0;
	
	sockaddr_in address;
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);
	address.sin_port = htons(port);
	
	int sockfd = sock(PF_INET, SOCK_STREAM, 0);
	assert(sockfd >= 0);
	
	int ret = bind(sockfd, (struct sockaddr*)&address, sizeof(address));
	assert(ret != -1);
	
	int ret = listen(sockfd, 5);
	assert(ret != -1);
	
	sockaddr client_address;
	sockaddr_len client_addrlength = sizeof(client_address);
	int connfd = accept(sockfd, (struct sockaddr*)&client_address, &client_addrlength);
	
	if(connfd < 0){
		printf("errno is: %d\n", errno);
		close(listenfd);
	}
	
	char buf[1024];
	fd_set read_fds;
	fd_set exception_fds;
	FD_ZERO(&read_fds);
	FD_ZERO(&exception_fds);
	
	while(1){
		memset(buf, '\0', sizeof(buf));
		FD_SET(connfd, &read_fds);
		FD_SET(connfd, &exception_fds);
		
		ret = select(connfd + 1, read_fds, NULL, exception_fds, NULL);
		if(ret < 0){
			printf("select failure\n");
			break;
		}
		
		if(FD_ISSET(connfd, &read_fds)){
			ret = recv(connfd, buf, sizeof(buf) - 1, 0);
			if(ret <= 0){
				break;
			}
			printf("get %d bytes of normal data: %s\n", ret, buf);
		}
		if(FD_ISSET(connfd, &exceptions_fds)){
			ret = recv(connfd, buf, sizeof(buf) - 1, MSG_OOB);
			if(ret <= 0){
				break;
			}
			printf("get %d bytes of oob data: %s\n", ret, buf);
		}
	}
	close(connfd);
	close(listenfd);
	return 0;
}




