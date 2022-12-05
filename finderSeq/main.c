#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "commonFunctions.h"

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
    printf("There are %d twin prime numbers between 0 and %d\n", countPrimeNumbers(array, n), n);
    /*printPrimeNumbers(array, n);*/
    printf("There are %d twin prime numbers between 0 and %d\n", countTwinPrimeNumbers(array, n), n);
    /*printTwinPrimeNumbers(array, n);*/
    printf("Real time/CPU time: %f seconds\n", (double)(endClock - startClock) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}
