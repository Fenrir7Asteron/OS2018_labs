#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of the array.\n");
    scanf("%d", &n);
    
    int *arr = malloc(n * sizeof(int));
    int i = 0;

    printf("Array is: ");
    for (; i < n; ++i) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
