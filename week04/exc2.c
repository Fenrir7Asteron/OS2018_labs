#include <stdio.h>
#include <sys/types.h>

void main() {
    int i;
    for (i = 0; i < 5; ++i) {
        fork();
        sleep(5);
    }
}
