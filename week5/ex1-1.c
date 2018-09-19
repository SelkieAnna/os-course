#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_routine(void* args) {
	printf("Hi, I'm thread %d\n", args);
	printf("Closing thread %d\n", args);
	pthread_exit(NULL);
}

int main() {
	pthread_t* thread = malloc(sizeof(pthread_t)*5);
	int i;
	for (i = 0; i < 5; i++) {
        	pthread_create(&thread[i], NULL, thread_routine, (void*) i);
		printf("Thread %d created\n", i);
		pthread_join(thread[i], NULL);
	}
	free(thread);
	return 0;
}
