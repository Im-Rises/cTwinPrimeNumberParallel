#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void siegeOfEratosthenes(char* array, int n);
void* allocateMemory(size_t size);
void populateArray(char* array, int n);
void printPrimeNumbersCount(char* array, int n);
void printPrimeNumbers(char* array, int n);
void printTwinPrimeNumbersCount(char* array, int n);
void printTwinPrimeNumbers(char* array, int n);

int main(int argc, char* argv[]) {
    printf("|-----Sieve of Eratosthenes Sequential-----|\n\n");
    if (argc != 2)
    {
        printf("Usage: %s <n> where n is the maximum value to search for twin primes", argv[0]);
        return 1;
    }

    /* Init variables */
    int n = atoi(argv[1]);
    char* array = allocateMemory(sizeof(char) * n);
    populateArray(array, n);

    /* Start timer */
    clock_t startClock = clock();

    /* Sieve of Eratosthenes */
    siegeOfEratosthenes(array, n);

    /* Stop timer */
    clock_t endClock = clock();

    /* Print results */
    printPrimeNumbersCount(array, n);
    /*    printPrimeNumbers(array, n);*/
    printTwinPrimeNumbersCount(array, n);
    /*printTwinPrimeNumbers(array, n);*/
    printf("Real time/CPU time: %f seconds\n", (double)(endClock - startClock) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}

/*void siegeOfEratosthenes(int n) {
    int* primes = allocateMemory(n * sizeof(int));
    populateArray(primes, n);

    int i;
    int j;
    for (i = 2; i < n; i++)
    {
        if (primes[i] == 1)
        {
            for (j = i * i; j < n; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    printPrimeNumbers(primes, n);

    printTwinPrimeNumbers(primes, n);

    free(primes);
}*/

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

void printPrimeNumbersCount(char* array, int n) {
    int count = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (array[i] == 1)
        {
            count++;
        }
    }
    printf("There are %d prime numbers between 0 and %d\n", count, n);
}

void printPrimeNumbers(char* array, int n) {
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

void printTwinPrimeNumbersCount(char* array, int n) {
    int count = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (array[i] == 1 && array[i + 2] == 1)
        {
            count += 1;
        }
    }

    printf("There are %d twin prime numbers between 0 and %d\n", count, n);
}

void printTwinPrimeNumbers(char* array, int n) {
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
