#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint_interceptor(int sig){
	printf("Signal %d was intercepted\n", sig);
	return;
}

int main(){
	signal(SIGINT, sigint_interceptor);
	while(1){
		printf("Still alive\n");
		sleep(1);
	}
	return 0;
}