#include <stdio.h>
#include <unistd.h>

int main() {
	char str[31] = "Hi, I'm a string with some text";
	int fd[2];
	if (pipe(fd) == 0) {
		pid_t f;
		f = fork();
		if (f == 0) {
			sleep(1);
			char other_str[31] = "\0";
			read(fd[0], other_str, sizeof(char) * 31);
			printf("%s\n", other_str);
		} else {
			write(fd[1], str, sizeof(char) * 31);
		}
	} else return 1;
	sleep (1);
	return 0;
}
