#include <stdio.h>
//
//int array2[3];
//int array[3];
////指针实参
//void fun1(int *ptr) {
//    ptr[0] = 3;
////    *ptr = 3;
//    ptr = array2;
//}
//
////数组实参
//void fun2(int arr[]) {
////    arr[0] = 4;
//    *arr = 4;
//    arr = array2;
//}
//
//void func1(char ca[]) {
//    printf("&ca: %#x; &(ca[0]): %#x; &(ca[1]): %#x;\n", ca, &(ca[0]), &(ca[1]));
//}
//
//void func2(char * pa) {
//    printf("&pa: %#x; &(pa[0]): %#x; &(pa[1]): %#x; ++pa: %#x\n", pa, &(pa[0]), &(pa[1]), ++pa);
//}
//
//char ga[] = "abc";
//
//int main() {
////    printf("array[0]: %d\n", array[0]);
////    fun1(array);
////    printf("array[1]: %d\n", array[1]);
////    fun2(array);
////    printf("array[0]: %d\n", array[0]);
////    array[0] = 5;
////    printf("array[0]: %d\n", array[0]);
////    *(array + 1) = 6;
////    printf("array[1]: %d\n", array[1]);
//////    array = array2;
////
////int * p = array;
////p[2] = 6;
////    printf("%d\n", array[2]);
////    func1(ga);
//    func2(ga);
//
//printf("ga: %#x; &ga: %#x; &(ga[0]): %#x; &(ga[1]): %#x\n", ga, &ga, &(ga[0]), &(ga[1]));
//
//
//    return 0;
//}


char ga[] = "abcdefghijklm";

void my_array_func(char ca[10]) {
    printf(" addr of array param = %#x \n", &ca);
    printf(" addr (ca[0]) = %#x \n", &(ca[0]));
    printf(" addr (ca[1]) = %#x \n", &(ca[1]));
}

void my_pointer_func(char * pa) {
    printf(" addr of ptr param = %#x \n", &pa);
    printf(" addr (pa[0]) = %#x \n", &(pa[0]));
    printf(" addr (pa[1]) = %#x \n", &(pa[1]));
    printf(" ++pa = %#x \n", ++pa);
}

int main() {
    printf(" addr of global array = %#x \n", &ga+1);
    printf(" addr (ga[0]) = %#x \n", &(ga[0]));
    printf(" addr (ga[1]) = %#x \n", &(ga[1]));
    my_array_func(ga);
    my_pointer_func(ga);
}