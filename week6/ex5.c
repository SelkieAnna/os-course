#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main() {
	pid_t p;
	p = fork();
	if (p == 0) {
		while (1) {
			printf("I'm alive\n");
			sleep(1);
		}
	} else {
		sleep(10);
		kill(0, SIGTERM);
	}
	return 0;
}


