static void handle_child(int sig){
	pid_t pid;
	int stat;
	while((pid = waitpid(-1, &stat, WNOHANG)) > 0){
		//handle the child
	}
}