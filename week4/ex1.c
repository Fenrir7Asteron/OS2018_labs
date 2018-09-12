#include <stdio.h>
#include <sys/types.h>

#define SOME_NUMBER 39;

void main() {
    int n = SOME_NUMBER;
    int pid2 = fork();
    int pid1 = getpid();
    
    if (pid2) {
	printf("Hello from parent [%d - %d]\n", pid1, n);
    } else {
	printf("Hello from child [%d - %d]\n", pid1, n);
    }   
}
