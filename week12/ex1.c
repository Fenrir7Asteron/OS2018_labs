#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


#define FILENAME "/dev/random"
#define SIZE 20

int main(int argc, char *argv[])
{
    int i;
    int fd;
    int result;
    char *map;

    fd = open(FILENAME, O_RDWR, (mode_t)0400);
    if (fd == -1) {
	perror("Error opening file for writing");
	exit(EXIT_FAILURE);
    }
    
    char *string = malloc(SIZE);
    read(fd, string, SIZE);
    printf("%s\n", string);

    close(fd);
    return 0;
}
