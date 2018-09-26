#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void sig_usr1_handler(int signo) {
    printf("\nCatched SIGUSR1. Closing.\n");
    exit(0);
}

void sig_kill_handler(int signo) {
    exit(0);
}

void sig_stop_handler(int signo) {
    printf("\nCatched SIGSTOP. Going to sleep.\n");
    wait();
}

int main() {
    signal(SIGUSR1, sig_usr1_handler);
    signal(SIGKILL, sig_kill_handler);
    signal(SIGSTOP, sig_stop_handler);    
    while (1) {
	sleep(1);
    }
}
