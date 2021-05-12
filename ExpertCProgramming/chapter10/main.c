#include <stdio.h>
#include <malloc.h>
#include <setjmp.h>

int (*paf())[20] {
    int (*pear)[20];
    pear =calloc(20, sizeof(int));
    if (!pear)
        longjmp();
    return pear;
}

int main() {
    int (*res)[20];
    res = paf();
    (*res)[1] = 12;
    printf("%d, %d\n", (*res)[0], (*res)[1]);

    return 0;
}
