#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int* arr, int n) {
    int i;
    for (i = 1; i < n; ++i) {
       int j;
       for (j = i; j > 0; --j) {
           if (arr[j] < arr[j - 1]) {
               swap(arr + j, arr + j - 1);
           }
       }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*) malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }    
    
    bubble_sort(arr, n);
    
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
