#include <stdio.h>

float average(int  arr, int size) {
    int sum;

    printf("   arr: %p\n", &arr);
    printf(" size: %p\n", &size);
    printf(" sum: %p\n", &sum);

    for (int i = 0; i < size; i++) {
//        sum += arr[i];
    }

    return (sum * 1.0f) / size;
}

int main() {
    int arr[] = {1,2,3};
    printf("%p\n", arr);
    average(3, 3);
    float x;
    printf("   x: %p\n", &x);


    return 0;
}
