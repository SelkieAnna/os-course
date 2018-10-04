#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	do {
		printf("How many integers do you want to store in the array?\n");
		scanf("%d", &n);
		if (n < 1) {
			printf("The number should be greater than 0\n");
		}
	} while (n < 1);
	int *array = malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++) {
		array[i] = i;
	}
	printf("Your array is:");
	for (i = 0; i < n; i++) {
		printf(" %d", array[i]);
	}
	printf("\n");
	free(array);
	return 0;
}
