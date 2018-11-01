#include <stdio.h>
#include <unistd.h>

int main(void) {
	printf("Hel\nlo");
	fork();
	printf("\n");
	return 0;
}