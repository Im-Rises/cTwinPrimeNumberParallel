#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_VALUE 100

void* allocateMemory(size_t size);
void populateArrayAscendingly(int* array, int n);
void printArray(int* array, int size, int* outputArray);

void SieveOfEratosthenes(int n)
{
    int* prime = allocateMemory(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++)
        prime[i] = 1;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == 1) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            printf("%d ",p);
}

int main(int argc, char* argv[]) {
//    int* array = allocateMemory(sizeof(int) * MAX_VALUE);
//    int* outputArray = allocateMemory(sizeof(int) * MAX_VALUE);
//
//    populateArrayAscendingly(array, MAX_VALUE);
//
//    for (int i = 0; i < MAX_VALUE; i++)
//    {
//        outputArray[i] = 1;
//    }
//
//    SieveOfEratosthenes(array, MAX_VALUE, outputArray);
//
//    printArray(array, MAX_VALUE, outputArray);
//
//    int i;
//    int count = 0;
//    for (i = 0; i < MAX_VALUE; i++)
//    {
//        if (array[i] == 1)
//        {
//            count++;
//        }
//    }
//    printf("There are %d prime numbers between %d and %d", count, MAX_VALUE);
//
//    free(array);

    SieveOfEratosthenes(MAX_VALUE);
    return 0;
}

void* allocateMemory(size_t size) {
    void* memory = malloc(size);
    if (memory == NULL)
    {
        fprintf(stderr, "Error allocating memory");
        exit(2);
    }
    return memory;
}

void populateArrayAscendingly(int* array, int n) {
    int i;
    for (i = 0; i < n; i++)
    {
        array[i] = i;
    }
}

void printArray(int* array, int size, int* outputArray) {
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d is prime : %d\n", array[i], outputArray[i]);
    }
    printf("\n");
}
