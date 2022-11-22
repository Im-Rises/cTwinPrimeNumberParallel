#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MIN_VALUE 2
#define MAX_VALUE 100 + 1

void* allocateMemory(size_t size);
void populateArrayAscendingly(int minValue, int maxValue, int* array);
void printArray(int* array, int size);

int main(int argc, char* argv[]) {
    int* array = allocateMemory((MAX_VALUE - MIN_VALUE) * sizeof(int));
    populateArrayAscendingly(MIN_VALUE, MAX_VALUE, array);
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

void populateArrayAscendingly(int minValue, int maxValue, int* array) {
    int i;
    for (i = 0; i + minValue < maxValue; i++)
    {
        array[i] = i + minValue;
    }
}

void printArray(int* array, int size) {
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
