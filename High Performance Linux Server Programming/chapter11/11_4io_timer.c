#define TIMEOUT 5000

int timeout = TIMEOUT;
time_t start = time(NULL);
time_t end = time(NULL);

while(1){
	printf("ther timeout is now %d mil-seconds\n", timeout);
	start = time(NULL);
	int ret = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, timeout);
	if(ret < 0 && errno != EINTR){
		printf("epoll failed\n");
		break;
	} else if(ret == 0){
		/*��ʱʱ�䵽*/
		timeout = TIMEOUT;
		//handle the timeout task
		continue;
	}
	end = time(NULL);
	/*����´�epoll_wait���õĳ�ʱ����*/
	timeout -= (end - start)*1000;
	if(timeout <= 0){
		timeout = TIMEOUT;
		//handle the timeout task
	}
	//handle connection
}