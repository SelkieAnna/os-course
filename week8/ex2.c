#include <stdlib.h>

int main() {
	char * buff[10];
	int size = 10 * 1024 * 1024;
	int i;
	for (i = 0; i < 10; i++) {
		buff[i] = calloc(size, 1);
		sleep(1);
	}
	for (i = 0; i < 10; i++) {
		free(buff[i]);
	}
	return 0;
}
