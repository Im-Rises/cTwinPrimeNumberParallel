#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MIN_VALUE 2
#define MAX_VALUE 100

typedef struct PrimeNumberState PrimeNumberState;
struct PrimeNumberState {
    int value;
    int isPrime;
};

void* allocateMemory(size_t size);
void populateArrayAscendingly(int minValue, int maxValue, PrimeNumberState* array);
void printArray(PrimeNumberState* array, int size);

void findTwinPrimeNumbers(PrimeNumberState* array, int size);

int main(int argc, char* argv[]) {
    struct PrimeNumberState* array = allocateMemory((MAX_VALUE - MIN_VALUE) * sizeof(PrimeNumberState));
    populateArrayAscendingly(MIN_VALUE, MAX_VALUE, array);

    findTwinPrimeNumbers(array, MAX_VALUE - MIN_VALUE);

    printArray(array, MAX_VALUE - MIN_VALUE);

    free(array);
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

void populateArrayAscendingly(int minValue, int maxValue, PrimeNumberState* array) {
    int i;
    for (i = 0; i + minValue < maxValue; i++)
    {
        array[i].value = i + minValue;
        array[i].isPrime = 1;
    }
}

void printArray(PrimeNumberState* array, int size) {
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d is prime : %d\n", array[i].value, array[i].isPrime);
    }
    printf("\n");
}

void findTwinPrimeNumbers(PrimeNumberState* array, int size) {
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (array[i].value % 2 == 0)
        {
            array[i].isPrime = 0;
        }
    }

    //    int k = array[0].value;
    //    while (k * k <= size)
    //    {
    //        int j;
    //        for (j = 0; j < size; j++)
    //        {
    //            if (array[j].value % k == 0 && array[j].value != k)
    //            {
    //                array[j].isPrime = 0;
    //            }
    //        }
    //        k++;
    //    }
}
