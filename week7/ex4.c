#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *my_realloc(void *ptr,int size) {
	if (size <= 0) {
		free(ptr);
		return NULL;
	} else {
		void *temp = malloc(size);
		if (ptr != NULL) {
			memcpy(temp, ptr, size);
			free(ptr);
		}
		return temp;
	}
}

int main() {
	int *arr = malloc(3 * sizeof(int));
	int i;
	for (i = 0; i < 3; i++) {
		arr[i] = i;
	}
	for (i = 0; i < 3; i++) {
                printf("%d ", arr[i]);
        }
	printf("\n");
	arr = my_realloc(arr, 7 * sizeof(int));
	for (i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
