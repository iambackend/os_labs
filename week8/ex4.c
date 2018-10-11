#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

#define TEN_MB 10000000

int main(){
	for(int i = 0; i < 10; i++){
		int* a = malloc(TEN_MB);
		memset(a, 0, TEN_MB);
		struct rusage u;
		getrusage(RUSAGE_SELF, &u);
		printf("Used %d bytes of memory\n", u.ru_maxrss);
		sleep(1);
		// free() is for losers
	}
}