#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int n;
    
    if (argc == 2) {
        sscanf(argv[1], "%d", &n);
    } else {
        printf("There should be 2 arguments but provided %d\n", argc);
        return 1;
    }
    
    int *page_frame = malloc(n * sizeof(int));
    int *age = calloc(n, sizeof(int));
    int number_of_pages = 0, hit = 0;
    int i = 0;
    
    for (; i < n; ++i) {
        age[i] = -1;
    }
    
    FILE *input;
    input = fopen("input.txt", "r");    
    if (input) {
        char str[255];
        while (fscanf(input, "%s", str)!=EOF) {
            int page = 0;
            i = 0;
            while (str[i] != 0) {
                page = page * 10 + (str[i] - '0');
                ++i;
            }
            ++number_of_pages;
            
            for (i = 0; i < n; ++i) {
                age[i] >>= 1;
            }
            
            int min_age = age[0];
            int index_of_min_age = 0;
            int found = 0;
            for (i = 0; i < n; ++i) {                
                if (page_frame[i] == page) {
                    ++hit;
                    found = 1;
                    break;
                }
                
                if (min_age > age[i]) {
                    min_age = age[i];
                    index_of_min_age = i;
                }
            }
            
            if (!found) {
                page_frame[index_of_min_age] = page;
                age[index_of_min_age] = 1 << 30;
            }
        }
        fclose(input);
    }
    
    printf("Number of pages: %d\nNumber of hits: %d\nNumber of misses: %d\n", number_of_pages, hit, number_of_pages - hit);
    printf("Hit rate: %f%%\n", ((double) hit) / (number_of_pages - hit));
}
