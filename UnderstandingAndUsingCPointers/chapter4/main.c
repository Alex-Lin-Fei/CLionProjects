#include <stdio.h>
#include <malloc.h>

void displayArray(int arr[], int size) {
    printf("arr size: %d\n", sizeof arr);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayPointer(int * * arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr+i) = (int*)malloc(sizeof(int));
        printf("%p \n", arr[i]);
        **(arr+i) = i;
    }
    printf("\n");
}

void test1() {
    int rows = 3;
    int columns = 5;

    int ** matrix = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(columns*sizeof (int));
        printf("%p  ", matrix[i]);
    }
}


void test2() {
    int rows = 3;
    int columns = 5;

    int ** matrix = (int**) malloc(rows * sizeof(int*));
    matrix[0] = (int *) malloc(rows * columns * sizeof(int));
    for (int i = 0; i < rows; i++) {
        matrix[i] = matrix[0] + i * columns * sizeof (int);
        printf("%p  ", matrix[i]);
    }
}


int main() {
    int vector[5] = {1,2,3,4,5};
    printf("%d\n", sizeof vector / sizeof(int));

    printf("&vector: %p; vector: %p; &vector[0]: %p\n", &vector, vector, &vector[0]);
    printf("&vector: %p; vector: %p; &vector[0]: %p\n", &vector+1, vector+1, &vector[0]+1);

    displayArray(vector, 5);
    int* arr[5];
    displayPointer(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%p %d ", arr[i], *arr[i]);
//test2();

    return 0;
}
