#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_COUNT 1000
#define TRUE 1
#define FALSE 0
int producer_awake;
int consumer_awake;
int count;

void* producer_routine(void* args) {
	while (TRUE) {
		while (producer_awake) {
			if (count == MAX_COUNT) {
				producer_awake = FALSE;
				break;
			}
			count++;
			if (count > 0) consumer_awake = TRUE;
		}
	}
}

void* consumer_routine(void* args) {
	while (TRUE) {
                while (consumer_awake) {
                        if (count == 0) {       
                                consumer_awake = FALSE;
                                break;
                        }
                        count--;
                        if (count < MAX_COUNT) producer_awake = TRUE;
                }
        }
}

void* print_routine(void* args) {
	while (TRUE) {
		printf("The size of buffer is %d. The status of producer is %d. The status of consumer is %d.\n", count, producer_awake, consumer_awake);
		sleep(5);
	}
}

int main() {
	count = 0;
	pthread_t prod_thread;						// threads initialization
	pthread_t cons_thread;
	pthread_t print_thread;
	producer_awake = TRUE;						// statuses assignment
	consumer_awake = TRUE;
       	pthread_create(&prod_thread, NULL, producer_routine, NULL);	// threads satert
	pthread_create(&cons_thread, NULL, consumer_routine, NULL);
	pthread_create(&print_thread, NULL, print_routine, NULL);
	pthread_join(prod_thread, NULL);				// not closing the program while the thread functions are running
	pthread_join(cons_thread, NULL);
	return 0;
}
