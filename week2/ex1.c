#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char *argv[]) {
    int x = INT_MAX;
    float y = FLT_MAX;
    double z = DBL_MAX;

    printf("Integer size: %lu\nFloat size: %lu\nDouble size: %lu\n", sizeof(x), sizeof(y), sizeof(z));
    printf("Maximum integer: %d\nMaximum float: %f\nMaximum double: %lf\n", x, y, z);
}

