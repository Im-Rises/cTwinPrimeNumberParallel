#include "commonFunctions.h"

#include <string.h>
#include <stdio.h>

void siegeOfEratosthenes(char* array, int n) {
    populateArray(array, n);

    array[0] = 0;
    array[1] = 0;
    int k = 2;
    int i, j;
    while (k * k <= n)
    {
        for (j = k * k; j < n; j += k)
        {
            if ((j % k) == 0)
            {
                array[j] = 0;
            }
        }
        while (array[++k] == 0)
            ;
    }
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

void populateArray(char* array, int n) {
    int i;
    for (i = 2; i < n; i++)
    {
        array[i] = 1;
    }
}

int countPrimeNumbers(const char* array, int n) {
    int count = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
    }
    return count;
}

void printPrimeNumbers(const char* array, int n) {
    printf("The prime numbers are: ");
    int i;
    for (i = 0; i < n; i++)
    {
        if (array[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int countTwinPrimeNumbers(const char* array, int n) {
    int count = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (array[i] == 1 && array[i + 2] == 1)
        {
            count += 1;
        }
    }
    return count;
}

void printTwinPrimeNumbers(const char* array, int n) {
    printf("The twin prime numbers are: ");
    int i;
    for (i = 0; i < n; i++)
    {
        if (array[i] == 1 && array[i + 2] == 1)
        {
            printf("(%d, %d) ", i, i + 2);
        }
    }

    printf("\n");
}
