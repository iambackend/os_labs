#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Input N:\n");
	scanf("%d", &n);
	int *a = (int*) malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++){
		a[i] = i;
	}
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	free(a);
	return 0;
}