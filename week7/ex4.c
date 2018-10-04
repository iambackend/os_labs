#include <stdio.h>
#include <stdlib.h>

void* unrealloc(void *ptr, int new_size){
	if(ptr == NULL){
		return malloc(new_size);
	}
	// malloc_size() is a macos specific function, 
	// there are analogues for win and linux
	int old_size = malloc_size(ptr);
	if (new_size == 0){
		free(ptr);
		return NULL;
	} else if (new_size == old_size){
		return ptr;
	} else if (new_size < old_size){
		void *new_ptr = malloc(new_size);
		memcpy(new_ptr, ptr, new_size);
		free(ptr);
		return new_ptr;
	} else if (new_size > old_size){
		void *new_ptr = malloc(new_size);
		memcpy(new_ptr, ptr, old_size);
		free(ptr);
		return new_ptr;		
	}
}

int main(){
	int size = 10;
	int* arr = malloc(size*sizeof(int));
	while(1){
		printf("Current array have pointer %p contain this %d elements:\n", arr, size);
		for(int i = 0; i < size; i++){
			printf("%d ", arr[i]);
		}
		printf("\nWhat new size do you whant?: ");
		scanf("%d", &size);
		arr = unrealloc(arr, size * sizeof(int));
	}
	return 0;
}