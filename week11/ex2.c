#include <stdlib.h>
#include <stdio.h>

int main(){
	char str[] = "Hello";
	for(int i = 0; i < sizeof(str); i++){
		printf("%c", str[i]);
		sleep(1);
	}
	return 0; 
}