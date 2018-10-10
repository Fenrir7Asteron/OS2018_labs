#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB 1024 * 1024

int main() {
    int i = 0;
    for (; i < 10; ++i) {
	char *arr = malloc(10 * MB);
	memset(arr, 0, 10 * MB);
	sleep(1);
    }
}
