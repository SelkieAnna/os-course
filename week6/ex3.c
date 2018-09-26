#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void intercept(int signl) {
	printf("\nInterrupt Signal was caught\n");
}

int main() {
	signal(SIGINT, intercept);
	while (1) {
		sleep(1);
	}
	return 0;
}


