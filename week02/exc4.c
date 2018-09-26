#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(int argc, char *argv[]) {
    int *a, *b, x, y;
    scanf("%d%d", &x, &y);
    a = &x;
    b = &y;
    swap(a, b);
    printf("%d %d\n", x, y);
}
