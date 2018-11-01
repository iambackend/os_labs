#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	int input = open("ex1.txt", O_RDONLY);
	int output = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	struct stat *stat_buff = (struct stat *)malloc(sizeof(struct stat));
	fstat(input, stat_buff);
	off_t size = stat_buff->st_size;
	ftruncate(output, size);
	char *instr = (char *)mmap(NULL, size, PROT_READ, MAP_SHARED, input, 0);
	printf("%p\n", instr);
	char *outstr = (char *)mmap(NULL, size, PROT_WRITE, MAP_SHARED, output, 0);
	printf("%p\n", outstr);
	memcpy(outstr, instr, size);
	munmap(instr, size);
	munmap(outstr, size);
	free(stat_buff);
	return 0; 
}