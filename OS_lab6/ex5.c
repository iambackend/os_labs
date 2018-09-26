#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
	int kinda_child_pid = fork();
	if(kinda_child_pid == 0){
		while(1){
			printf("I’m alive\n");
			sleep(1);
		}
	} else {
		sleep(10);
		kill(kinda_child_pid, SIGTERM);
	}
	return 0;
}