#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdarg.h>


/**/
int lookup_keyword(char const * const desired_word,
                   char const * keyword_table[], int const size) {
    char const **kwp;

    /*
     * 对于表中每个单词
     * */
    for (kwp = keyword_table; kwp < keyword_table + size; kwp++)
        if (strcmp(desired_word, *kwp))
            return kwp - keyword_table;
    return -1;
}

/*
 * exercise 1
 * */



/*
 * exercise 2
 * */



/*
 * exercise 3
 * */
bool identity_matrix(int matrix[10][10]) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (matrix[i][j] != (i==j))
                return false;
    return true;
}


/*
 * exercise 4
 * */
bool n_identity_matrix(int * line, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (*line++ != (i == j))
                return false;
    return true;
}

/*
 * exercise 5
 * */

void matrix_multiply(int * m1, int * m2, int * r, int x, int y, int z) {
    for (int i = 0; i < x; i++)
        for (int j = 0; j < z; j++) {
            for (int k = 0; k < y; k++) {
                *r += *(m1 + i * y + k) * *(m2 + k * z + j);
            }
            r++;
        }
}


/*
 * exercise 6
 * */
int array_offset(int arrayinfo[], ...) {
    va_list var_arg;
    va_start(var_arg, arrayinfo);
    int d = arrayinfo[0];

    int offset = 0;
    for (int i = 1; i <= d; i++) {
        int idx = va_arg(var_arg, int);
        offset *= arrayinfo[i*2] - arrayinfo[i*2-1] + 1;
        offset += idx - arrayinfo[i*2-1];
    }
    return offset;
}





int main() {
    int m1[][2] = {
            {2,-6},
            {3,5},
            {1,-1}
    };
    int m2[][4] = {
            {4,-2,-4,-5},
            {-7,-3,6,7}
    };

    int r[3][4]={0}; //初始化
//    int * r = (int *) calloc(3 * 4, sizeof(int));

    matrix_multiply(m1[0], m2[0], r[0], 3,2,4);
    int sum = 12;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", r[i][j]);
        printf("\n");

    }

    int arrayinfo[] = {3,4,6,1,5,-3,3};
    printf("%d ", array_offset(arrayinfo ,6,3,1));


    return 0;
}
