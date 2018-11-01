#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	int file = open("ex1.txt", O_RDWR);
	struct stat *stat_buff = (struct stat *)malloc(sizeof(struct stat));
	stat("ex1.txt", stat_buff);
	off_t size = stat_buff->st_size;
	printf("Initial file size is %lld bytes\n", size);
	char new_str[] = "This is a nice day";
	ftruncate(file, sizeof(new_str));
	char *str = (char *)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
	strcpy(str, new_str);
	munmap(str, size);
	stat("ex1.txt", stat_buff);
	printf("Final file size is %lld bytes\n", stat_buff->st_size);
	free(stat_buff);
	return 0; 
}