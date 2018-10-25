#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>


unsigned long long inodes[1000];
int icounters[1000];
char *inames[1000][100];
int icount = 0;

int main(int argc, char *argv[]) {

	DIR *directory = opendir(argv[1]);
	struct dirent *file;

	while ((file = readdir(directory)) != NULL) {
		struct stat *buff = malloc(sizeof(struct stat));
		char *name = file->d_name;
		stat(file->d_name, buff);
		unsigned long long inode = buff->st_ino;
		int i;
		// printf("%s %llu %d\n", name, buff->st_ino, buff->st_nlink);
		for (i = 0; i < icount; i++) {
			if (inode == inodes[i]) {
				inames[i][icounters[i]++] = name;
				break;
			}
		}
		if (i == icount) {
			inodes[icount++] = inode;
			inames[i][icounters[i]++] = name;
		}
		free(buff);
	}

	for (int i = 0; i < icount; i++) {
		if(icounters[i] < 2) continue;
		printf("i-node %llu is used by this files:\n", inodes[i]);
		for(int j = 0; j < icounters[i]; j++){
			printf("    %s\n", inames[i][j]);
		}
	}
}