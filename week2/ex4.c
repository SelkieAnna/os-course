#include <stdio.h>

int main(){
	int a, b;
	printf("Enter the first (integer) number: ");
	scanf("%d", &a);
	printf("Enter the second number: ");
	scanf("%d", &b);
	swap(&a, &b);
	printf("Numbers have been swapped.\nThe first one now is %d.\nThe second one now is %d.\n", a, b);
	return 0;
}

int swap(int *f, int *s) {
	int t = *f;
	*f = *s;
	*s = t;
}
