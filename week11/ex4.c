#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


#define INFILENAME "ex1.txt"
#define OUTFILENAME "ex1.memcpy.txt"

int main(int argc, char *argv[])
{
    int i;
    int fdin, fdout;
    int result;
    char *src, *dst;
    struct stat input_stat;

    fdin = open(INFILENAME, O_RDONLY, (mode_t)0600);
    if (fdin == -1) {
	perror("Error opening file for writing");
	exit(EXIT_FAILURE);
    }

    result = lstat(INFILENAME, &input_stat);
    if (result == -1) {
    perror("Error calling lstat() to get input file data");
    exit(EXIT_FAILURE);
    }
    
    fdout = open(OUTFILENAME, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
    if (fdout == -1) {
	perror("Error opening file for writing");
	exit(EXIT_FAILURE);
    }
    
    result = lseek(fdout, input_stat.st_size-1, SEEK_SET);
    if (result == -1) {
	close(fdout);
	perror("Error calling lseek() to 'stretch' the file");
	exit(EXIT_FAILURE);
    }
    
    result = write(fdout, "", 1);
    if (result != 1) {
	close(fdout);
	perror("Error writing last byte of the file");
	exit(EXIT_FAILURE);
    }

    src = mmap(0, input_stat.st_size, PROT_READ, MAP_SHARED, fdin, 0);
    if (src == MAP_FAILED) {
	close(fdin);
	perror("Error mmapping the file");
	exit(EXIT_FAILURE);
    }
    
    dst = mmap(0, input_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0);
    if (dst == MAP_FAILED) {
	close(fdout);
	perror("Error mmapping the file");
	exit(EXIT_FAILURE);
    }
    
    memcpy(dst, src, input_stat.st_size);
    
    if (munmap(src, input_stat.st_size) == -1) {
	perror("Error un-mmapping the file");
    }
    
    if (munmap(dst, input_stat.st_size) == -1) {
	perror("Error un-mmapping the file");
    }

    close(fdin);
    close(fdout);
    return 0;
}
