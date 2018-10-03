#include <stdio.h>
#include <stdlib.h>

int main() {
    char **s = malloc(10 * sizeof(char*)); // Can not dereference not initialized pointers (causes segmentation fault), hence we need to allocate some memory.
    char *foo = "Hello World";
    *s = foo;
    printf("s is %s\n", foo);
    s[0] = foo;
    printf("s is %s\n", s[0]);
    return 0;
}
