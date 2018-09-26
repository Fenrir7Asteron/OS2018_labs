#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void sig_term_handler(int signo) {
    printf("Catched SIGTERM. Closing.\n");
    exit(0);
}

int main() {
    int pid = fork();
    if (pid == 0) {
        signal(SIGTERM, sig_term_handler);
	while (1) {
            printf("I am alive!\n");
	    sleep(1);
        }
    } else {
	sleep(10);
	kill(pid, SIGTERM); 
    }
}
