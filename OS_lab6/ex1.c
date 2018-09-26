#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int xxx[2];
	pipe(xxx);
	char in[] = "Duck is duck.";
	char out[80];
	write(xxx[1], in, sizeof(in));
	read(xxx[0], out, sizeof(out));
	printf("From pipeline: %s\n", out);
}
