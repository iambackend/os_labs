#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int xxx[2];
	pipe(xxx);
	if(fork() == 0){
		char out[80];
		read(xxx[0], out, sizeof(out));
		printf("Hello from other side: %s\n", out);
	} else {
		char in[] = "Duck is duck.";
		write(xxx[1], in, sizeof(in));
		printf("Hello from this side\n");
	}
}