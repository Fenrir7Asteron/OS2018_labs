#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int pipefd[2];
    char *str1 = "SOME TEXT", *str2 = "";
    pipe(pipefd);
    
    if (fork() == 0) {
        printf("String1: %s\n", str1);
        printf("String2 before: %s\n", str2);

        read(pipefd[0], &str2, 1);
        close(pipefd[0]);
        close(pipefd[1]);
        printf("String2 after: %s\n", str2);
    } else {
	write(pipefd[1], &str1, strlen(str1));
    }
}
