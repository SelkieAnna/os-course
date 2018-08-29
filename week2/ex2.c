#include <stdio.h>
#include <string.h>

int main(){
	char string[200];
	printf("Enter any string: ");
	scanf("%[^\n]", string);
	printf("Reverse string: ");
	int i;
	for (i = strlen(string); i >= 0; i--) {
		printf("%c", string[i]);
	}
	printf("\n");
	return 0;
}
