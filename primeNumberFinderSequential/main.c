#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_VALUE 100

void siegeOfEratosthenes(int n);
void* allocateMemory(size_t size);
void populateArray(int* array, int n);
// void printArray(int* array, int size);
void printPrimeNumbers(int* array, int n);
void printTwinPrimeNumbers(int* array, int n);

int main(int argc, char* argv[]) {
    siegeOfEratosthenes(MAX_VALUE);
    return 0;
}

void siegeOfEratosthenes(int n) {
    int* prime = allocateMemory(sizeof(int) * n);
    populateArray(prime, n);

    int k = 2;
    while (k * k <= n)
    {
        // a) Mark all multiples of k between k^2 and n as non-prime
        for (int j = k * k; j < n; j += k)
        {
            if ((j % k) == 0)
            {
                prime[j] = 0;
            }
        }
        // b) Find the smallest number greater than k that is not marked
        for (int i = k + 1; i < n; i++)
        {
            if (prime[i] == 1)
            {
                k = i;
                break;
            }
        }
    }

    printPrimeNumbers(prime, n);
    printTwinPrimeNumbers(prime, n);

    free(prime);
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

void populateArray(int* array, int n) {
    array[0] = 0;
    array[1] = 0;
    for (int i = 2; i < n; i++)
    {
        array[i] = 1;
    }
}

// void printArray(int* array, int size, int* outputArray) {
//     int i;
//     for (i = 0; i < size; i++)
//     {
//         printf("%d is prime : %d\n", array[i], outputArray[i]);
//     }
//     printf("\n");
// }

void printPrimeNumbers(int* array, int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
    }
    printf("There are %d prime numbers between 0 and %d\n", count, n);

    printf("The prime numbers are: ");
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void printTwinPrimeNumbers(int* array, int n) {
    printf("The twin prime numbers are: ");
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 1 && array[i + 2] == 1)
        {
            printf("(%d, %d) ", i, i + 2);
        }
    }

    printf("\n");
}
