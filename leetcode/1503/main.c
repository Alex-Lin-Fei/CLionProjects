#include <stdio.h>
#include <math.h>

int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize) {
    int len = 0;
    for (int i = 0; i < leftSize; i++) {
        if (left[i] > len)
            len = left[i];
    }

    for (int i = 0; i < rightSize; i++)
        if (n - right[i] > len)
            len = n - right[i];
    return len;
}

int main() {
    int left[]={4,3}, right[] = {0,1};

    printf("%d\n", getLastMoment(4, left,2, right, 2));
    return 0;
}
