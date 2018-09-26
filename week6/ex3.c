#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void sig_int_handler(int signo) {
    printf("\nCatched SIGINT. Closing.\n");
    exit(0);
}

int main() {
    signal(SIGINT, sig_int_handler);
    while (1) {
	sleep(1);
    }
}
