#include "./h/my_string.h"
#include "./h/map.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

short error_check(char* str) {
    short flag = 0;
    
    for(short i = 0; str[i]; i++) {
        if(str[i] != '.' && str[i] != '\n' && str[i] != 'o') {
            flag = 1;
        }
        if(flag == 1) {
            return 1;
        }
    }
    return 0;
}

short error(short flag) {
    if(flag == 0) printf("error map\n");
    if(flag == 1) printf("No such file\n");
    return 1;
}

int main(int ac, char** av) {
    if(ac == 1) return error(1);
    short fd = open(av[1], O_RDONLY);
    if(fd == -1) return error(1);
    struct stat f_stat;
    stat(av[1], &f_stat);
    short size = (short)f_stat.st_size;
    if(size == 0) return error(0);
    char* content = (char*)calloc(sizeof(char), size + 1);
    read(fd, content, size);
    if(error_check(content) == 1) {
        free(content);
        return error(0);
    }
    close(fd);
    int** map = my_split(content);
    free(content);
    map = my_square(map);
    char** arr = redraw_map(map);
    for(fd = 0; arr[fd]; fd++) {printf("%s\n", arr[fd]);}
    for(fd = 0;arr[fd];fd++) {free(arr[fd]);}
    for(fd = 0; map[fd]; fd++) {free(map[fd]);}
    free(map);
    free(arr);
    return 0;
}
