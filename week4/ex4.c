#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_ARGUMENTS 100
#define MAX_WORD_SIZE 32

void main() {
    while (1) {
	char *input = malloc(MAX_WORD_SIZE * MAX_NUMBER_OF_ARGUMENTS);
        char *argv[MAX_NUMBER_OF_ARGUMENTS];
        char *envp[] = { NULL };

	int i;
        for (i = 0; i < MAX_NUMBER_OF_ARGUMENTS; ++i) {
 	    argv[i] = malloc(MAX_WORD_SIZE);
        }      

        fgets(input, MAX_WORD_SIZE * MAX_NUMBER_OF_ARGUMENTS, stdin);

	i = 0;
	int j = 0;
	int k = 0; 
		
	while (1) {
	    if (input[j] == '\0') {
		argv[i++][k] = '\0';
		break;
	    }

            if (input[j] != ' ') {
		argv[i][k++] = input[j++];
	    } else {
		argv[i++][k] = '\0';
		++j;
		k = 0;
		continue;
	    }
	}
	argv[i] = NULL;

	char *command = argv[0];

        int pid = fork();
        if (pid == 0) {
	    if (i > 1) {
                execvpe(command, argv, envp);
	    } else {
                system(command);
	    }
	    exit(0);
	}

        if (command[0] == 'e' && command[1] == 'x' && command[2] == 'i' && command[3] == 't' && command[4] == '\0') {
	    break;
        }
    }
}	
