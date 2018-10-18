#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int LEFTMOST_BIT = 1 << sizeof(int) * 8 - 2; 

bool check_memory(int *memory, int size, int page){
	for(int i = 0; i < size; i++){
		if(memory[i] == page) {
			return true;
		}
	}
	return false;
}

void update_ages(int* memory, int *ages, int size, int recently_used){
	for(int i = 0; i < size; i++){
		ages[i] >> 1;
		if(ages[i] == recently_used)
			ages[i] += LEFTMOST_BIT;
	}
}

void swap_in(int* memory, int* ages, int size, int page){
	int min_age_page = 0;
	for(int i = 0; i < size; i++){
		if(memory[i] == 0){
			min_age_page = i;
			break;
		}
		if(ages[i] <= ages[min_age_page]){
			min_age_page = i;
		}
	}
	memory[min_age_page] = page;
	ages[min_age_page] = 0;
}

int main(int argc, char **argv) {
	int n = atoi(argv[1]);
	FILE * file;
	file = fopen( "input.txt" , "r");
	int next_page;
	int hit = 0, miss = 0;
	int memory[100];
	int ages[100];
	memset(memory, 0, 100 * sizeof(int));
	memset(ages, 0, 100 * sizeof(int));
	for(int i = 0; fscanf(file, "%d", &next_page) != EOF; i++){
		if(check_memory(memory, n, next_page)) hit++;
		else {
			miss++;
			swap_in(memory, ages, n, next_page);
		}
		update_ages(memory, ages, n, next_page);
		// for(int i = 0; i < n; i++){
		// 	printf("%d ", memory[i]);
		// }
		// printf("\n");
	}
	fclose(file);
	printf("Hit/Miss ratio: %d/%d = %f\n", hit, miss, (double)hit/miss);
}