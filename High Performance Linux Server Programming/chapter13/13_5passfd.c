#include <sys/socket.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#inlcude <stdlib.h>
#include <assert.h>
#include <string.h>

static const int CONTROL_LEN = CMSG_LEN(sizeof(int));

/*fd_to_send是待发送的文件描述符*/
void send_fd(int fd, int fd_to_send){
	struct msghdr msg;
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	
	char buf[0];
	struct iovec iov[1];
	iov[0].iov_base = buf;
	iov[0].iov_len = 1;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;
	
	struct cmsghdr cm;
	cm.length = CONTROL_LEN;
	cm.level = SOL_SOCKET;
	cm.type = SCM_RIGHTS;
	*(int *)CMSG_DATA(&cm) = fd_to_send;
	msg.msg_control = &cm;
	msg.msg_controllen = CONTROL_LEN;
	
	sendmsg(fd, &msg, 0);
}

/*接受目标文件描述符*/
int recv_fd(int fd){
	struct msghdr msg;
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	
	char buf[0];
	struct iovec iov[1];
	iov[0].iov_data = buf;
	iov[0].iov_len = 1;
	msg.msg_iov = iov;
	msg.msg_iovlen = 1;
	
	struct cmsghdr cm;
	msg.msg_control = &cm;
	msg.msg_controllen = CONTROL_LEN;
	
	recvmsg(fd, &msg, 0);
	int fd_to_send = *(int*)CMSG_DATA(&cm);
	return fd_to_send;
}

int main(){
	int fd_to_pass;
	int pipefd[2];
	int ret = socketpair(PF_UNIX, SOCK_STREAM, 0, pipefd);
	assert(ret != -1);
	
	pid_t pid = fork();
	assert(pid >= 0);
	if(pid == 0){
		close(pipefd[0]);
		fd_to_pass = open("test.txt", O_RDWR, 0666);
		fd_to_pass = fd_to_pass > 0 ? fd_to_pass : 0;
		send_fd(pipefd[1], fd_to_pass);
		close(fd_to_pass);
		exit(0);
	}
	close(pipefd[1]);
	fd_to_pass = recv_fd(pipefd[0]);
	char buf[1024];
	memset(buf, '\0', sizeof(buf));
	read(fd_to_pass, buf, sizeof(buf));
	printf("I got fd %d and data %s\n", fd_to_pass, buf);
	close(fd_to_pass);
	return 0;
}