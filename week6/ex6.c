#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main() {
	int fd[2];
	pipe(fd);
	int status;
	pid_t p1;
	printf("Creating child 1...\n");
	p1 = fork();
	if (p1 != 0) {	// if it's a parent process
		pid_t p2;
		printf("Creating child 2...\n");
		p2 = fork();
		if (p2 != 0) {
			write(fd[1], &p2, sizeof(pid_t));
			printf("Waiting for child 2...\n");
			waitpid(p2, &status, WUNTRACED);
			printf("Child 2 was stopped\n");
		} else {	// if it's child 2
			while(1);
		}
	} else {	// if it's child 1
		sleep(2);
		pid_t p;
		read(fd[0], &p, sizeof(pid_t));
		kill(p, SIGSTOP);
	}
	return 0;
}
