#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, i, j;
	sscanf(argv[1], "%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i; j++) {
			printf(" ");
		}
		for (j = 1; j <= 2*i-1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
