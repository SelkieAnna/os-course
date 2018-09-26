#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void kill_handler(int signl) {
	printf("\nKill Signal was caught\n");
}

void stop_handler(int signl) {
	printf("\nStop Signal was caught\n");
}

void usr1_handler(int signl) {
	printf("\nUSR1 Signal was caught\n");
}

int main() {
	signal(SIGKILL, kill_handler);
	signal(SIGSTOP, stop_handler);
	signal(SIGUSR1, usr1_handler);
	while (1) {
		sleep(1);
	}
	return 0;
}


