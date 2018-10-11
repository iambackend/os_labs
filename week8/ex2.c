#include <stdio.h>
#include <stdlib.h>

#define TEN_MB 30000000

int main(){
	for(int i = 0; i < 20; i++){
		int* a = malloc(TEN_MB);
		memset(a, 0, TEN_MB);
		sleep(1);
		// free() is for losers
	}
}