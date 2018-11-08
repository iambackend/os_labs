#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void prnt(char *str, int *files, int n, int k) {
	for(int i = 0; i < n; i++) {
		write(files[i], str, k);
	}
}

int main(int argc, char **argv) {

	int i = 1, n = argc, files[argc], opt = O_TRUNC;
	if(argc >= 2 && strcmp(argv[1], "-a") == 0) i++, n--, opt = O_APPEND;
	for(int j = 0; i < argc; i++, j++){
		files[j] = open(argv[i], O_CREAT | O_WRONLY | opt, 644);
	}
	files[n - 1] = open("/dev/stdout", O_WRONLY);

	char str[1000];
	int k;
	int input = open("/dev/stdin", O_RDONLY);
	while((k = read(input, str, sizeof(str) - 1)) > 0) {
		prnt(str, files, n, k);
	}
	return 0;
}

