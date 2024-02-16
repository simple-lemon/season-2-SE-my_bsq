#include "../h/my_string.h"

void fill_minus(int** map, short index1, short index2) {
    short i, j;
    for(i = 0; i<index1; i++) {
        for(j = 0; j < index2; j++) {
            map[i][j] = -1;
        }
    }
}

int** my_split(char* content) {
    short size1 = 1,size2 = 0;
    short i;
    for(i = 0; content[i]; i++) {
        if(content[i] == '\n') size1++;
    }
    int** map = (int**)malloc(sizeof(int**)* (size1 + 1));
    map[size1] = NULL;
    for(;content[size2] != '\n'; size2++) {}
    for(i=0; i<size1; i++) {
        map[i] = (int*)malloc(sizeof(int*)*(size2 + 1));
    }
    fill_minus(map, size1, size2 + 1);
    size1 = 0;
    size2 = 0;
    for(i=0; content[i]; i++) {
        if(content[i] == '\n') {
            size1++;

            size2 = 0;
            continue;
        }
        else if(content[i] == '.') {
            map[size1][size2++] = 1;
        }
        else if(content[i] == 'o'){
            map[size1][size2++] = 0;
        }
    }
    return map;
}

char** redraw_map(int** map) {
    short len1 = 0, len2 = 0, i, j;
    for(; map[len1]; len1++) {
        for(len2 = 0;map[len1][len2] != -1; len2++);
    }
    char** arr = (char**)malloc(sizeof(char*)*(len1 + 1));
    arr[len1] = NULL;
    for(i = 0; i < len1; i++) {
        arr[i] = (char*)calloc(sizeof(char), len2+1);
        for(j = 0; j < len2; j++) {
            if(map[i][j] == 1) {
                arr[i][j] = '.';
            }
            if(map[i][j] == 0) {
                arr[i][j] = 'o';
            }
            if(map[i][j] == -2) {
                arr[i][j] = 'x';
            }
        }
    }
    return arr;
}

short my_isdigit(char c) {
    if(c >= 48 && c <= 57) {
        return 1;
    }
    return 0;
}
