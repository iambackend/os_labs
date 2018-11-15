#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int opt;
	int n  = 5, m = 3;
	while ((opt = getopt(argc, argv, "n:m:")) != -1) {
		switch (opt) {
		case 'n':
			n = atoi(optarg);
			break;
		case 't':
			m = atoi(optarg);
			break;
		default: /* '?' */
			fprintf(stderr, "Usage: %s [-n n] [-m m]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	int e[m]; // I 
	int a[m]; // HAVE 
	int finished[n]; // NO
	int c[n][m]; // IDEA
	int r[n][m]; // Or i don't understand something about runtime array allocation,
				 // or it's some kind of dark magic of clang on macos.
	FILE* input = fopen("input.txt", "r");

	for(int i = 0; i < m; i++) {
		fscanf(input, "%d", &e[i]);
	}
	for(int i = 0; i < m; i++) {
		fscanf(input, "%d", &a[i]);
		finished[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			fscanf(input, "%d", &c[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			fscanf(input, "%d", &r[i][j]);
		}
	}
	int fin, chosen;
	for(fin = 0, chosen = 1; fin < n && chosen == 1;) {
		chosen = 0;
		for(int i = 0; i < n; i++) {
			if(finished[i]) continue;
			int b = 1;
			for(int j = 0; j < m; j++) {
				if(r[i][j] > a[j]) {
					b = 0;
					break;
				}
			}
			if(b) {
				fin++;
				chosen = 1;
				finished[i] = 1;
				for(int j = 0; j < m; j++){
					a[j] += c[i][j];
				}
			}
		}
	}
	FILE* output = fopen("output.txt", "w");
	if(fin == n) {
		printf("All is fine!\n");
		fprintf(output, "no deadlocked processes.\n");
	} else {
		printf("I am sorry for your loss.\n");
		fprintf(output, "List of deadlocked processes:\n");
		for(int i = 0; i < n; i++) {
			if(!finished[i]) fprintf(output, "%d ", i);
		}
	}
}