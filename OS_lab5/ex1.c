#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define N 10

void *thread_work(void *arg){
	printf("Thread number %d is running.\n", (int) arg);
	pthread_exit(NULL);
}

int main(int argc, char **argv){
	for (int i = 0; i < N; i++) {
		pthread_t thread;

		printf("Starting thread %d\n", i);
		pthread_create(&thread, NULL, thread_work, (void *) i);
		int result = pthread_join(thread, NULL);
		printf("Thread %d exited with code %d\n\n", i, result);
	}
	return 0;
}
