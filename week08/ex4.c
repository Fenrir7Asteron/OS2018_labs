#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>

#define MB 1024 * 1024

int main() {
    int i = 0;
    for (; i < 10; ++i) {
	char *arr = malloc(10 * MB);
	struct rusage usage;
	memset(arr, 0, 10 * MB);	
	getrusage(RUSAGE_SELF, &usage);
	printf("maxrss: %ld\n", usage.ru_maxrss);
	printf("ixrss: %ld\n", usage.ru_ixrss);
	printf("minflt: %ld\n", usage.ru_minflt);
	printf("majflt: %ld\n", usage.ru_majflt);
	printf("nvcsw: %ld\n", usage.ru_nvcsw);
	printf("nivcsw: %ld\n\n", usage.ru_nivcsw);
	sleep(1);
    }
}
