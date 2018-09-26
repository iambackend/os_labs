#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

int main(){
	int xxx[2];
	pipe(xxx);
	int kinda_first_child_pid = fork();
	if(kinda_first_child_pid == 0){			//first child
		printf("Look at me, I`m mr. First!\n");
		close(xxx[1]);
		int kinda_second_child_pid;
		read(xxx[0], &kinda_second_child_pid, sizeof(kinda_second_child_pid));
		printf("1: PID of mr. Second is %d.\n", kinda_second_child_pid);
		sleep(4);
		printf("1: I`m sick of mr. Second! I`ll kill him!!!\n");
		kill(kinda_second_child_pid, SIGTERM);
	} else {
		int kinda_second_child_pid = fork();
		if(kinda_second_child_pid == 0){	//second child
			printf("Look at me, I`m mr. Second!\n");
			while(1){
				sleep(1);
				printf("2: Mr. First looking at me oddly...\n");
			}
		} else {							//father
			printf("Look at me, I`m mr. Zero!\n");
			printf("0: PID of mr. Second is %d.\n", kinda_second_child_pid);
			close(xxx[0]);
			write(xxx[1], &kinda_second_child_pid, sizeof(kinda_second_child_pid));
			int status;
			waitpid(kinda_second_child_pid, &status, 0);
			printf("0: Mr. Second finished with status %d\n", status);
		}
	}
	return 0;
}