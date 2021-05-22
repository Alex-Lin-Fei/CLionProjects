#include <stdio.h>
#include <assert.h>
#include <malloc.h>
//#define PINT int *

typedef  int* PINT;
int main() {
    PINT ptr1, ptr2;
    ptr1 = (PINT) malloc(2);
    printf("%d %d\n", sizeof ptr1, sizeof ptr2);
    free(ptr1);
//    ptr1 = NULL;
    free(ptr1);

    return 0;
}

