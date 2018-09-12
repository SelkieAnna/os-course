#include <stdio.h>
#include <unistd.h>

int main() {
	int n = 42;
	int pid = fork();
	if (pid == 0) {
		printf("Hello from child [%d - %d]\n", getpid(), n);
	} else if (pid > 0) {
		printf("Hello from parent [%d - %d]\n", getpid(), n);
	} else {
		printf("ERROR WHILE FORKING RUN FOREST RUN");
		return 1;
	}
	return 0;
}

