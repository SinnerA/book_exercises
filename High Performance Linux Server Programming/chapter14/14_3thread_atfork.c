#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

pthread_mutex_t mutex;

void* another(){
	printf("in child thread, lock the mutex\n");
	pthread_mutex_lock(&mutex);
	sleep(5);
	pthread_muitex_unlock(&mutex);
}

void prepare(){
	pthread_mutex_lock(&mutex);
}

void infork(){
	pthread_mutex_unlock(&mutex);
}

int main(){
	pthread_mutex_init(&mutex, NULL);
	pthread_t id;
	pthread_create(&id, NULL, another, NULL);
	//pthread_atfork(prepare, infork, infork);//«Â¿Ìª•≥‚À¯◊¥Ã¨
	
	sleep(1);
	pid_t pid = fork();
	if(pid < 0){
		pthread_join(id, NULL);
		pthread_mutex_destory(&mutex);
		return 1;
	} else if(pid == 0){
		printf("I am in the child, want to get the lock\n");
		pthread_mutex_lock(&mutex);
		printf("I can not run to here, oop...\n");
		pthread_mutex_unlock(&mutex);
		exit(0);
	}
	pthread_join(id, NULL);
	pthread_mutex_destory(&mutex);
	return 0;
}