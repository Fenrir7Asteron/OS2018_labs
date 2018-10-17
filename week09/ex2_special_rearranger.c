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
    int counter[1000];
    int i = 0;
    
    for (; i < n; ++i) {
        age[i] = -1;
    }
    
    for (i = 0; i < 1000; ++i) {
        counter[i] = 0;
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
            ++counter[page];
        }
        fclose(input);
    }
    int rearranged_input[number_of_pages];
    for (i = 0; i < number_of_pages; ++i) {
        rearranged_input[i] = 0;
    }
    
    for (i = 0; i < 1000; ++i) {
        if (counter[i] > 1) {
            int j;
            for (j = 0; j < number_of_pages; ++j) {
                if (!rearranged_input[j]) {
                    rearranged_input[j] = i;
                    --counter[i];
                    break;
                }
            }
            
            while (counter[i] > 0) {
                int k = 2 * n;
                for (j = j + 1; j < number_of_pages; ++j) {
                    if (!rearranged_input[j] && k <= 0) {
                        --counter[i];
                        rearranged_input[j] = i;
                        break;
                    } else {
                        --k;
                    }
                }
                if (j == number_of_pages) {
                    break;
                }
            }
        }
    }

    for (i = 0; i < 1000; ++i) {
        while (counter[i] > 0) {
            int j;
            for (j = 0; j < number_of_pages; ++j) {
                if (!rearranged_input[j]) {
                    rearranged_input[j] = i;
                    --counter[i];
                    break;
                }
            }
        }
    }
    
    FILE *output;
    output = fopen("input_special_rearranging.txt", "w"); 
    for (i = 0; i < number_of_pages; ++i) {
        char str[12];
        sprintf(str, "%d ", rearranged_input[i]);
        fputs(str, output);
    }
    fclose(output);
}
