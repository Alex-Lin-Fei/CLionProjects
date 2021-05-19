#include <stdio.h>

#define TYPE short

void print(TYPE * pv) {
    printf("before: %p; after: %p\n", pv, pv-1);
}

//指针算术
void testPointer() {
    TYPE t = 1;
    TYPE * p1 = &t;
    print(p1);
//    printf("%p %p\n", p1, p1+1);
    TYPE type[] = {1,2,3};
    TYPE * p2 = &type[0];
    print(p2);
//    printf("%p %p\n", p2, p2+1);
//    void * pv = p1;
//    printf("%p %p\n", pv,  pv+1);
}

int main() {
    int num;
    int * pi = &num;
    printf("Value of pi: %p\n", pi);
    void * pv = pi;
    pi = (int *) pv;
    printf("Value of pi: %p\n", pi);
    size_t size = sizeof(void*); //OK
    size_t siz = sizeof(void); //ERROR
    printf("%d %d\n", size, siz);
    printf("%lu\n", sizeof(double*));

    testPointer();

    return 0;
}
