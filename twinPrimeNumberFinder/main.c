#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

//#define MAX_VALUE 100

void* allocateMemory(size_t size);
void populateAscendingArray(int* array, int n);
void printArray(int* array, int size, int* outputArray);

void siegeOfEratosthenes();

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

    //    SieveOfEratosthenes(MAX_VALUE);
    siegeOfEratosthenes();
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

void populateAscendingArray(int* array, int n) {
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

void siegeOfEratosthenes() {
    int n = 1000;
    int* array = allocateMemory(sizeof(int) * n);
    int* outputArray = allocateMemory(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        array[i] = i;
        outputArray[i] = 1;
    }

    int k = 2;
    while (k * k <= n)
    {
        for (int i = k * k; i <= n; i += k)
        {
            outputArray[i] = 0;
        }
        //        for (int i = k + 1; i <= n; i++)
        //        {
        //            if (outputArray[i] == 1)
        //            {
        //                k = i;
        //                break;
        //            }
        //        }
        k++;
    }

    for (int i = 0; i < n; i++)
    {
        if (outputArray[i] == 1)
        {
            printf("%d ", array[i]);
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (outputArray[i] == 1)
        {
            count++;
        }
    }
    printf("There are %d prime numbers between 0 and %d", count, n);
}
