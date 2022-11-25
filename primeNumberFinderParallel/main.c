#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

//#define MAX_VALUE 100

void* allocateMemory(size_t size);
// void populateAscendingArray(int* array, int n);
void populateArray(int* array, int n, int* outputArray);
void printArray(int* array, int size, int* outputArray);
void printPrimeNumbers(int* array, int n, int* outputArray);
void printTwinPrimeNumbers(int* array, int n, const int* outputArray);

void siegeOfEratosthenesV1();
void siegeOfEratosthenesV2();
void siegeOfEratosthenesV3();

int main(int argc, char* argv[]) {
    siegeOfEratosthenesV1();
    //    siegeOfEratosthenesV2();
    //    siegeOfEratosthenesV3();
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

// void populateAscendingArray(int* array, int n) {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         array[i] = i;
//     }
// }

void printArray(int* array, int size, int* outputArray) {
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d is prime : %d\n", array[i], outputArray[i]);
    }
    printf("\n");
}

void populateArray(int* array, int n, int* outputArray) {
    int i;
    for (i = 0; i < n; i++)
    {
        array[i] = i;
    }

    for (i = 0; i < n; i++)
    {
        outputArray[i] = 1;
    }
}

void printPrimeNumbers(int* array, int n, int* outputArray) {

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
    printf("There are %d prime numbers between 0 and %d\n", count, n);
}

void printTwinPrimeNumbers(int* array, int n, const int* outputArray) {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (outputArray[i] == 1 && outputArray[i + 2] == 1)
        {
            printf("(%d, %d) ", array[i], array[i + 2]);
            count++;
        }
    }
    printf("There are %d twin prime numbers between 0 and %d\n", count, n);
}

void siegeOfEratosthenesV1() {
    int n = 100;
    int* array = allocateMemory(sizeof(int) * n);
    int* outputArray = allocateMemory(sizeof(int) * n);
    populateArray(array, n, outputArray);

    int k = 2;
    while (k * k <= n)
    {
        // a) Mark all multiples of k between k^2 and n as non-prime
        for (int j = k * k; j < n; j += k)
        {
            if (j % k == 0)
            {
                outputArray[j] = 0;
            }
        }
        // b) Find the smallest number greater than k that is not marked
        for (int i = k + 1; i < n; i++)
        {
            if (outputArray[i] == 1)
            {
                k = array[i];
                break;
            }
        }
    }

    printPrimeNumbers(array, n, outputArray);
    printTwinPrimeNumbers(array, n, outputArray);

    free(array);
    free(outputArray);
}

void siegeOfEratosthenesV2() {
    int n = 100;
    int* array = allocateMemory(sizeof(int) * n);
    int* outputArray = allocateMemory(sizeof(int) * n);
    populateArray(array, n, outputArray);

    int k = 2;
    while (k * k <= n)
    {
        for (int i = k * k; i < n; i += k)
        {
            outputArray[i] = 0;
        }
        k++;
    }

    printPrimeNumbers(array, n, outputArray);

    free(array);
    free(outputArray);
}

void siegeOfEratosthenesV3() {
    int n = 100;
    int* array = allocateMemory((n + 1) * sizeof(int));
    int* prime = allocateMemory((n + 1) * sizeof(int));

    populateArray(array, n, prime);

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == 1)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }

    printPrimeNumbers(array, n, prime);

    free(prime);
    free(array);
}
