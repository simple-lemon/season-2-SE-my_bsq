#ifndef MY_BSQ_H_MY_STRING_H_
#define MY_BSQ_H_MY_STRING_H_

#include <stdlib.h>
int** my_split(char* content);
short my_isdigit(char c);
void fill_minus(int** map, short index1, short index2);
char** redraw_map(int** map);
#endif
