#include <stdlib.h>
#include <stdio.h>
#include <sys/resource.h>

int main() {
	struct rusage usage;
	char * buff[10];
	int size = 10 * 1024 * 1024;
	int i;
	for (i = 0; i < 10; i++) {
		buff[i] = calloc(size, 1);
		getrusage(RUSAGE_SELF, &usage);
		printf("Application's memory usage is %ld bytes \n", &usage.ru_maxrss);
		sleep(1);
	}
	for (i = 0; i < 10; i++) {
		free(buff[i]);
	}
	return 0;
}
