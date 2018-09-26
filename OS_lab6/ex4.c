#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_interceptor(int sig){
	printf("Signal %d was intercepted\n", sig);
	exit(0);
	return;
}

int main(){
	signal(SIGINT, signal_interceptor);
	signal(SIGKILL, signal_interceptor);
	signal(SIGTERM, signal_interceptor);
	signal(SIGUSR1, signal_interceptor);
	while(1){
		printf("Still alive\n");
		sleep(1);
	}
	return 0;
}