#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char str[100];

    printf("Input a string: ");
    scanf("%[^\n]s%*c", str);
    printf("%s\n", str);

    int length = strlen(str);
    int i;
    for (i = length - 1; i >= 0; --i) {
        printf("%c", str[i]);
    }
    printf("\n");
}
