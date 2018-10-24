#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main() {
	char buff[100];
	char comm[100];
	char filepath[100];
	struct stat info;
	DIR *dir;
	struct dirent *file;
	dir = opendir("./tmp/");
	while ((file = readdir(dir)) != NULL) {
		if  (strcmp((*file).d_name, ".") != 0 && strcmp((*file).d_name, "..") != 0) {
			strcpy(filepath, "./tmp/");
			strcat(filepath, (*file).d_name);
			stat(filepath, &info);
			if (info.st_nlink >= 2) {
				strcpy(comm, "find . -inum ");
				sprintf(buff, "%d", info.st_ino);
				strcat(comm, buff);
				strcat(comm, " -printf \"%f \"");
				system(comm);
				printf("\n");
			}
		}
	}
	closedir(dir);
	return 0;
}
