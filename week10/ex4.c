#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_FILE_NUMBER 1000
#define MAX_NAME_LENGTH 50

struct file {
    long i_node_number;
    char* name;
};

int main() {
    char *dir_name = "tmp";
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        return 1;
    }
    
    struct dirent *entry;
    struct file *array_of_files = malloc(sizeof(struct file) * MAX_FILE_NUMBER);
    int i = 0;
    for (; i < MAX_FILE_NUMBER; ++i) {
        array_of_files[i].name = malloc(MAX_NAME_LENGTH);
    }
    i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        struct stat statbuf;
        char *path = malloc(PATH_MAX);
        
        strncpy( path, dir_name, PATH_MAX);
        strncat( path, "/", PATH_MAX );
        strncat( path, entry->d_name, PATH_MAX );
        stat(path, &statbuf);
        long number_of_hard_links = (long) statbuf.st_nlink;
        if (number_of_hard_links >= 2) {
            array_of_files[i].i_node_number = (long) statbuf.st_ino;
            strcpy(array_of_files[i].name, entry->d_name); 
            ++i;
        }
    }
    
    int n = i;
    for (i = 1; i < n; ++i) {
        int j = i;
        for (; j > 0; --j) {
            if (array_of_files[j].i_node_number < array_of_files[j - 1].i_node_number) {
                struct file temp = array_of_files[j];
                array_of_files[j] = array_of_files[j - 1];
                array_of_files[j - 1] = temp;
            }
        }
    }
    
    for (i = 0; i < n; ++i) {
        long i_node = array_of_files[i].i_node_number;
        long i_node_prev = -1;
        if (i > 0) {
            i_node_prev = array_of_files[i - 1].i_node_number;
        }
        
        if (i_node != i_node_prev) {
            if (i > 0) {
                printf("\n");
            }
            
            printf("Files that have i_node #%ld are: ", i_node);
        }
        printf("%s ", array_of_files[i].name);
    }
    printf("\n");
    closedir(dir);
}
