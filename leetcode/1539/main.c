#include <stdio.h>

int findKthPositive(int* arr, int arrSize, int k) {
    int sum = 0;
    for (int i = 0; i < arrSize; i++) {
        if (i == 0 && arr[i] != 1 || i > 0 && arr[i] != arr[i - 1] + 1) {
            int gap;
            if (i == 0)
                gap = arr[i] - 1;
            else
                gap = arr[i] - (arr[i - 1] + 1);
            if (sum +gap>= k) {
                return (i == 0? 0:arr[i - 1]) + k-sum;
            }
            sum += gap;
        }
    }
    return arr[arrSize - 1] + k - sum;
}

int main() {
//    int A[10][20][20];
//    int (*p)[20][20] = A;
//
//    printf("%p %p\n", A, A + 1);
//    printf("%p %p\n", p, p + 1);
    int arr[7] = {2,3,5,7,9,11,14};
    printf("%d", findKthPositive(arr, 7,9));
    return 0;
}
