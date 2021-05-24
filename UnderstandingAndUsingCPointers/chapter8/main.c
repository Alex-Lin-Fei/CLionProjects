#include <stdio.h>
#include <malloc.h>
#include <bits/pthreadtypes.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    double * vectorA;
    double * vectorB;
    double sum;
    int length;
} VectorInfo;

typedef struct {
    VectorInfo * info;
    int beginningIndex;
} Product;

pthread_mutex_t mutexSum;

void dotProduct(void *prod) {
    Product * product = (Product*)prod;
    VectorInfo * vectorInfo = product->info;
    int beginningIndex = product->beginningIndex;
    int endingIndex = beginningIndex+vectorInfo->length;
    double total = 0;

    for (int i = beginningIndex; i < endingIndex; i++) {
        total += (vectorInfo->vectorA[i] * vectorInfo->vectorB[i]);
    }

    pthread_mutex_lock(&mutexSum);
    vectorInfo->sum += total;
    pthread_mutex_unlock(&mutexSum);

    pthread_exit((void*)0);
}

void threadExample() {
    VectorInfo vectorInfo;
    double vectorA[16], vectorB[16];

    for (int i = 0; i < 16; i++) {
        vectorA[i] = vectorB[i] = i * 1.0;
    }

    double sum;

    vectorInfo.vectorA = vectorA;
    vectorInfo.vectorB = vectorB;
    vectorInfo.length = 4;

    pthread_t threads[NUM_THREADS];

    void *status;
    pthread_attr_t attr;

    pthread_mutex_init(&mutexSum, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    int returnValue;
    int threadNumber;

    for (threadNumber = 0; threadNumber < NUM_THREADS; threadNumber++) {

    }
}

int main() {
    int num;
    int *pi = &num;
    printf("Before: %p\n", pi);
    int tmp = (int)pi;
    pi = (int*)tmp;
    printf("After: %p\n", pi);
    printf("Num Address: %p\n", &num);

    num = 0x12345678;

    char * pc = (char*)&num;
    for (int i = 0; i < 4; i++)
        printf("%p: %02x \n", pc, (unsigned char)*pc++);

    int arr[10];
    int * restrict restar = (int*)malloc(10 * sizeof(int));
    int *par = arr;

    for (int i = 0; i < 10; i++) {
        par[i] += 5;
        restar[i] += 5;
        arr[i] *= 2;
        par[i] += 3;
        restar[i] += 3;
    }




    return 0;
}
