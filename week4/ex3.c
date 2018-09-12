#include <stdio.h>

int main() {
	char command[20];
	while (1) {
		printf("Type a command: \n");
		fgets(command, 20, stdin);
		system(command);
	}
	return 0;
}
