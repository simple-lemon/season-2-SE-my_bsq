#include "../h/map.h"
#include "../h/my_string.h"
int three_in_min(int** map, short index1, short index2) {
    short min = -1, i1, i2, i3;
    i1 = map[index1 - 1][index2 -1];
    i2 = map[index1 - 1][index2];
    i3 = map[index1][index2 -1];
    if (i1 > 0 && (min == -1 || i1 < min)) {
        min = i1;
    }
    if (i2 > 0 && (min == -1 || i2 < min)) {
        min = i2;
    }
    if (i3 > 0 && (min == -1 || i3 < min)) {
        min = i3;
    }
    return min;
}

int* max_index(int** map) {
    short i, j,flag,index=0,flg,ind;
    int* max_i = (int*)malloc(sizeof(int)*3); 
    max_i[0] = 0;
    max_i[1] = 0;
    max_i[2] = 0;
    for(i = 2; map[i]; i++) {
        for(j = 2; map[i][j] != -1; j++) {
            if(map[i][j]!= 0){
                flag = 1;
                flg = 1;
                for (index = 0; map[i-index][j]!=-1 && map[i][j-index]!=-1 && map[i-index][j-index]!=-1; index++)
                {
                    if(map[i-index][j]>0 && map[i][j-index]>0){
                        flg = 1;
                        for(ind = 0; map[i-index][j-ind]!=-1; ind++) {
                            if(map[i-index][j-ind]<1) {
                                flg = 0;
                                break;
                            }
                        }
                        if(flg == 1) {
                            flag++;
                        }
                    }
                    if(flg == 0){
                        break;
                    }
                }
            }
            if (max_i[2]<flag && map[i][j]!= 0) {
                max_i[0]=j;
                max_i[1]=i;
                max_i[2]=flag;
            }
            
        } 
    }
    int *max_ind = (int*)malloc(sizeof(int)*2);
    max_ind[0]=max_i[0];
    max_ind[1]=max_i[1];
    free(max_i);
    return max_ind;
}


int** map_designation(int** map, short ind1, short ind2) {
    short index, i, j;
    if(ind1 < ind2) index = ind1;
    else {
        index = ind2;
    }
    map[ind1][ind2] = -2;
    for(i = 1; i < index; i++) {
        map[ind1 - i][ind2] = -2;
        map[ind1][ind2 - i] = -2;
        for(j = 1; j < index; j++) {
            map[ind1 - i][ind2 - j] = -2;
        }
    }
    for(i = 0; map[i]; i++) {
        for(j = 0; map[i][j] != -1; j++) {
            if(map[i][j] > 0) {
                map[i][j] = 1;
            }
        }
    }
    return map; 
}

int** my_square(int** map) {
    short index1 = 2, index2 = 2;
    for( ; map[index1]; index1++) {
        for(index2 = 2 ; map[index1][index2] != -1; index2++) {
            if(map[index1][index2] > 0) {
                map[index1][index2] += three_in_min(map, index1, index2);
            }
        }
    }
    int* max_ind = max_index(map);
    map = map_designation(map, max_ind[0], max_ind[1]);
    free(max_ind);
    return map;
}
