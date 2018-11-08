#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	char str[21]; // additional byte for null terminator character
	int file = open("/dev/urandom", O_RDONLY);
	read(file, str, sizeof(str) - 1);
	printf("%s\n", str);
}