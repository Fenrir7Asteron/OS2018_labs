#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#define COUPLE 2

void sig_stop_handler(int signo) {
    printf("Catched SIGSTOP. Going to sleep.\n");
    wait();
}

int main() {
    int pipefd[2];
    pipe(pipefd);

    signal(SIGSTOP, sig_stop_handler);

    if (fork() == 0) {
	printf("1st child pid: [%d]\n", getpid());

	sleep(COUPLE);

	printf("1st child: Reading pid of the second child.\n");
	int pid2 = 0;
	read(pipefd[0], &pid2, sizeof(pid2));
	close(pipefd[0]);
	
	printf("1st child: I's time to stop!\n");
	kill(pid2, SIGSTOP);
    } else {
	int pid = fork();
	if (pid == 0) {
    	    printf("2nd child pid: [%d]\n", getpid());

	    while (1) {
		printf("2nd child: I am alive!\n");
		sleep(1);
            }
    	} else {
	    printf("parent pid: [%d]\n", getpid());
	
	    printf("parent: Sending pid to the first child.\n");
	    write(pipefd[1], &pid, sizeof(pid));
	    close(pipefd[1]);

	    int status;
	    printf("parent: Waiting for changes.\n");
            waitpid(pid, &status, WUNTRACED);
	    printf("parent: I am alive! What year is it?\n");
	}        
    }   
}
