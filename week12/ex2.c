#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define STDOUT "/dev/tty"

int main(int argc, char *argv[])
{
    int a_mod = 0;
    int i = 1;
    int fd;
    int result;

    char *to_write;
    scanf("%s", to_write);
    int size = 0;
    while (to_write[size++]);
    
    if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'a') {
        a_mod = 1;
        ++i;
    }
    
    for (; i < argc; ++i) {
        char *file_name = argv[i];
        if (a_mod) {
            perror("A mod is on");
            fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, (mode_t)0600);
        } else {
            fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, (mode_t)0600);
        }
        
        result = write(fd, to_write, size);
        if (result == -1) {
            perror("Error writing to file");
            exit(EXIT_FAILURE);
        }
        
        close(fd);
    }
    
    fd = open(STDOUT, O_WRONLY, (mode_t)0600);
    result = write(fd, to_write, size);
    if (result == -1) {
        perror("Error writing to stdout");
        exit(EXIT_FAILURE);
    }
    close(fd);
    return 0;
}
