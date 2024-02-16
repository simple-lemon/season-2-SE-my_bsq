// gcc -g3 -fsanitize=address -o my_bsq my_bsq* c/my_string.c c/map.c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "./h/my_string.h"
#include "./h/map.h"


int error(short flag) {
    if(flag == 1) printf("error map\n");
    return 1;
}

int main(int ac, char** av) {
    if(ac == 1) {
        return error(1);
    }
    short fd = open(av[1], O_RDONLY);
    if(fd == -1) {
        return error(1);
    }
    struct stat f_stat;
    stat(av[1], &f_stat);
    short size = (short)f_stat.st_size;
    char *content = (char*)calloc(sizeof(char), size + 1);
    short flag = read(fd, content, size);
    if(flag == 0) {
        free(content);
        return error(1);
    }
    int** map = my_split(content);
    map = my_square(map);
    free(content);
    close(fd);
    char** arr = redraw_map(map);
    for(flag = 0; arr[flag]; flag++) {printf("%s\n", arr[flag]);}
    for(flag = 0; map[flag]; flag++) {free(map[flag]);}
    for(flag = 0; arr[flag]; flag++) {free(arr[flag]);}
    free(arr);
    free(map);
    return 0;
}
