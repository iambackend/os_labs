#include <stdlib.h>
#include <stdio.h>

int main() {
	int pid = fork(), n = 8841;
  	if(pid){
		printf("Hello from parent [%d - %d]\n", pid, n); 
	} else if(!pid){ 
		printf("Hello from child [%d - %d]\n", pid, n); 
	} else {
		return EXIT_FAILURE; 
	}
	return EXIT_SUCCESS; 
}
