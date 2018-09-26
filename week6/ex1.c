#include <stdio.h>
#include <unistd.h>

int main() {
	char str[31] = "Hi, I'm a string with some text";
	char other_str[31] = "\0";
	int fd[2];
	if (pipe(fd) == 0) {
		write(fd[1], str, sizeof(char) * 31);
		read(fd[0], other_str, sizeof(char) * 31);
		printf("%s\n", other_str);
	} else return 1;
	return 0;
}
