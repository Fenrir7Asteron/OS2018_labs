#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quick_sort(int* arr, int l, int r) {
    if (l >= r) {
        return;
    }

    int pivot = partition(arr, l, r);
    quick_sort(arr, l, pivot);
    quick_sort(arr, pivot + 1, r);
}

int partition(int* arr, int l, int r) {
    int size = r - l + 1;
    int pivot = arr[rand() % size + l];
    int i = l, j = r;
    while (1) {
        while (arr[i] < pivot) {
            ++i;
        }

        while (arr[j] > pivot) {
            --j;
        }

        if (i > j) {
            break;
        } else {
            swap(arr + i, arr + j);
	    ++i;
            --j;
        }
    }

    return j;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*) malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }    
    
    quick_sort(arr, 0, n - 1);
    
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
