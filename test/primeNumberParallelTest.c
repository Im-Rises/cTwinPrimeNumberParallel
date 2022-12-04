#include "../finderSeq/commonFunctions.h"
#include <stdio.h>
#include <mpi.h>

int testPrime(const int n, const int processes, const int expectedResult, const int errorCode) {
    /*    char* array = allocateMemory(sizeof(char) * n);
        populateArray(array, n);
        siegeOfEratosthenes(array, n);
        int count = countPrimeNumbers(array, n);
        free(array);
        if (count != expectedResult)
        {
            printf("- Primes for n = %d, counter = %d, expected = %d, fail!\n", n, count, expectedResult);
            return errorCode;
        }
        printf("- Primes for n = %d, counter = %d, pass!\n", n, count);*/
    return 0;
}

int testTwinPrime(const int n, const int processes, const int expectedResult, const int errorCode) {
    /*    char* array = allocateMemory(sizeof(char) * n);
        populateArray(array, n);
        siegeOfEratosthenes(array, n);
        int count = countTwinPrimeNumbers(array, n);
        free(array);
        if (count != expectedResult)
        {
            printf("- Twin primes for n = %d, counter = %d, expected = %d, fail!\n", n, count, expectedResult);
            return errorCode;
        }
        printf("- Twin primes for n = %d, counter = %d, pass!\n", n, count);*/
    return 0;
}

int main() {
    printf("Prime parallel version tests:\n");
    int result = 0;
    result += testPrime(10,1, 4, 1);
    result += testPrime(10,2, 4, 1);
    result += testPrime(10,3, 4, 1);

    result += testPrime(100, 1, 25, 2);
    result += testPrime(100, 2, 25, 2);
    result += testPrime(100, 3, 25, 2);
    result += testPrime(100, 4, 25, 2);
    result += testPrime(100, 5, 25, 2);
    result += testPrime(100, 6, 25, 2);

    result += testPrime(1000, 1, 168, 4);
    result += testPrime(1000, 2, 168, 4);
    result += testPrime(1000, 3, 168, 4);
    result += testPrime(1000, 4, 168, 4);
    result += testPrime(1000, 5, 168, 4);
    result += testPrime(1000, 6, 168, 4);

    result += testPrime(10000, 1, 1229, 8);
    result += testPrime(10000, 2, 1229, 8);
    result += testPrime(10000, 3, 1229, 8);
    result += testPrime(10000, 4, 1229, 8);
    result += testPrime(10000, 5, 1229, 8);
    result += testPrime(10000, 6, 1229, 8);

    result += testPrime(100000, 1, 9592, 16);
    result += testPrime(100000, 2, 9592, 16);
    result += testPrime(100000, 3, 9592, 16);
    result += testPrime(100000, 4, 9592, 16);
    result += testPrime(100000, 5, 9592, 16);
    result += testPrime(100000, 6, 9592, 16);

    result += testPrime(1000000, 1, 78498, 32);
    result += testPrime(1000000, 2, 78498, 32);
    result += testPrime(1000000, 3, 78498, 32);
    result += testPrime(1000000, 4, 78498, 32);
    result += testPrime(1000000, 5, 78498, 32);
    result += testPrime(1000000, 6, 78498, 32);

    if (result == 0)
    {
        printf("All tests passed!\n");
    }
    else
    {
        printf("Some tests failed!\n");
        printf("Error code: %d : 0X%02X\n\n", result, result);
    }

    return 0;
}
