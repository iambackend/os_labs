#include <stdio.h> 

void swap(int * a, int *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void bubble_sort(int *a, int n){
	for(int i = 1; i < n; i++){
		for(int j = 1;  j < n - i + 1; j++){
			if(a[j] < a[j - 1]) swap(&a[j], &a[j - 1]);
		}
	}
}

int main(){
	int a[5] = {5, 4, 3, 2, 1}; 
	bubble_sort(a, 5);
	for(int i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
