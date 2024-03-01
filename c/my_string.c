#include "../h/my_string.h"

void fill_minus(int** map, short ind1, short ind2) {
    short i, j;
    for(i = 0; i<ind1; i++) {
        for(j = 0; j<ind2; j++) {
            map[i][j] = -1;
        }
    }
}

int** my_split(char* content) {
    short size1 = 3, size2 = 2, i;
    for(i = 0; content[i]; i++) {
        if(content[i] == '\n') size1++;
    }
    int** map = (int**)malloc(sizeof(int*)*(size1 + 1));
    map[size1] = NULL;
    for(i = 0;content[i] != '\n'; i++) {size2++;}
    for(i = 0; i<size1;i++) {
        map[i] = (int*)malloc(sizeof(int*)*size2);
    }
    fill_minus(map, size1, size2);
    size1 = 1;
    size2 = 1;
    for(i = 0;content[i]; i++) {
        if(content[i] == '\n') {
            size1++;
            size2 = 1;
        }
        else if(content[i] == '.') {
            map[size1][size2++] = 1;
        }
        else if(content[i] == 111) {
            map[size1][size2++] = 0;
        }
    }
    return map;
}


char** redraw_map(int** map) {
    short len1 = 1, len2 = 1, i, j, ind1, ind2;
    for(; map[len1][1] != -1; len1++) {
        for(len2 = 1;map[len1][len2] != -1; len2++);
    }
    char** arr = (char**)malloc(sizeof(char*)*(len1));
    arr[len1 -1] = NULL;
    ind1 = 1;
    for(i = 0; i < len1 - 1; i++) {
        arr[i] = (char*)calloc(sizeof(char), len2);
        ind2 = 1;;
        for(j = 0; j < len2 - 1; j++) {
            if(map[ind1][ind2] > 0) {
                arr[i][j] = '.';
            }
            if(map[ind1][ind2] == 0) {
                arr[i][j] = 'o';
            }
            if(map[ind1][ind2] == -2) {
                arr[i][j] = 'x';
            }
            ind2++;
        }
        ind1++;
    }
    return arr;
}
