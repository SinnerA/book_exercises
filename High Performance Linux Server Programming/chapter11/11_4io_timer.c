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
		/*超时时间到*/
		timeout = TIMEOUT;
		//handle the timeout task
		continue;
	}
	end = time(NULL);
	/*获得下次epoll_wait调用的超时参数*/
	timeout -= (end - start)*1000;
	if(timeout <= 0){
		timeout = TIMEOUT;
		//handle the timeout task
	}
	//handle connection
}