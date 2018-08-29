#include <stdio.h>

void draw_triangle(int n) {
    int left = n - 1, right = n - 1;
    int i;
    for (i = 0; i < n; ++i) {
        int j;
	char str[2 * n];

        for (j = 0; j < 2 * n - 1; ++j) {
            if (j >= left && j <= right) {
                str[j] = '*';
            } else {
                str[j] = ' ';
            }
        }

	str[j] = '\0';
        printf("%s\n", str);

	--left;
        ++right;
    }
}

void draw_right_triangle(int n) {
    int i;
    for (i = 0; i < n; ++i) {
        int j;
        char str[2 * n];

        for (j = 0; j <= i; ++j) {
            str[j] = '*';
        }

        for (j = i + 1; j < 2 * n - 1; ++j) {
            str[j] = ' ';
        }

	str[j] = '\0';
        printf("%s\n", str);
    }
}

void draw_some_triangle(int n) {
    int i;
    int middle = n / 2 + 1;
    for (i = 1; i <= middle; ++i) {
        int j;
        char str[2 * n];
        
        for (j = 0; j < i; ++j) {
            str[j] = '*';
        }

        for (j = i; j < 2 * n - 1; ++j) {
            str[j] = ' ';
        }

	str[j] = '\0';
        printf("%s\n", str);
    }

    for (i = middle - 1; i > 0; --i) {
        int j;
        char str[2 * n];
        
        for (j = 0; j < i; ++j) {
            str[j] = '*';
        }

        for (j = i; j < 2 * n - 1; ++j) {
            str[j] = ' ';
        }

        printf("%s\n", str);
    }
}

void draw_square(int n) {
    int i, j;
    char str[n + 1];

    for (j = 0; j < n; ++j) {
        str[j] = '*';
    }
    str[n] = '\0';

    for (i = 0; i < n; ++i) {
        printf("%s\n", str);
    }
}


int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    draw_triangle(n);
    draw_right_triangle(n);
    draw_some_triangle(n);
    draw_square(n);
}
