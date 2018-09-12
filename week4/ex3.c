#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 32

void main() {
    while (1) {
        char *command = malloc(sizeof(MAX_WORD_SIZE));
        scanf("%s", command);

        system(command);

        if (command[0] == 'e' && command[1] == 'x' && command[2] == 'i' && command[3] == 't' && command[4] == '\0') {
	    break;
        }
    }
}
