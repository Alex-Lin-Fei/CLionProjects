#include <stdio.h>
#include <malloc.h>
float average(double  arr, int size) {
    int sum;

    printf("   arr: %p\n", &arr);
    printf(" size: %p\n", &size);
    printf(" sum: %p\n", &sum);
}

void passingAddressOfConstants(const int * num1, int *num2) {
//    *num1 = *num2;
}

int * allocateArray(int size, int value) {
//    int arr[size];
int * arr = (int*) malloc(sizeof(int)*3);
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
    return arr;
}

int (*fptr)(int);

int square(int num) {
    return num * num;
}

void testFptr() {
    int n = 5;
    fptr = square;
    printf("%d squared is %d\n", n, fptr(n));
}

int main() {
//    int arr[] = {1,2,3};
double arr = 12;
    printf("%p\n", &arr);
    average(3, 3);
    double x;
    printf("%p\n", &x);
    average(4,4);

    int * a  = allocateArray(3,3);
    for (int i = 0; i < 3; i++)
        printf("%d ", *a++);


    testFptr();

    return 0;
}
