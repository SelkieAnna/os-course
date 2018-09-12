#include <stdio.h>

int main() {
        char command[50];
        while (1) {
                printf("Type a command: \n");
                fgets(command, 50, stdin);
                system(command);
        }
        return 0;
}
