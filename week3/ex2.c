#include <stdio.h>
int bubble_sort(int[], int);
int swap(int*, int*);
 
int main() {
	printf("The test array is {10, 9, 15, 10, 5}\n");
	int testarr[5] = {10, 9, 15, 10, 5};
	int testlen = 5;
	bubble_sort(testarr, testlen);
	printf("The bubble sorted test array is ");
	int i;
	for (i = 0; i < testlen; i++) {
		printf("%d ", testarr[i]);
	}
	printf("\n");
	return 0;
}

int bubble_sort(int arr[], int len) {
	int i, j;
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr [j + 1]);
			}
		}	
	}
}

int swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
