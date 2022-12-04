#include "../finderSeq/commonFunctions.h"
#include <stdio.h>

int testPrime(const int n, const int expectedResult, const int errorCode) {
    char* array = allocateMemory(sizeof(char) * n);
    populateArray(array, n);
    siegeOfEratosthenes(array, n);
    int count = countPrimeNumbers(array, n);
    free(array);
    if (count != expectedResult)
    {
        printf("- Primes for n = %d, counter = %d, expected = %d, fail!\n", n, count, expectedResult);
        return errorCode;
    }
    printf("- Primes for n = %d, counter = %d, pass!\n", n, count);
    return 0;
}

int testTwinPrime(const int n, const int expectedResult, const int errorCode) {
    char* array = allocateMemory(sizeof(char) * n);
    populateArray(array, n);
    siegeOfEratosthenes(array, n);
    int count = countTwinPrimeNumbers(array, n);
    free(array);
    if (count != expectedResult)
    {
        printf("- Twin primes for n = %d, counter = %d, expected = %d, fail!\n", n, count, expectedResult);
        return errorCode;
    }
    printf("- Twin primes for n = %d, counter = %d, pass!\n", n, count);
    return 0;
}

int main() {
    printf("Prime and Twin prime sequential version tests\n");
    int result = 0;
    result += testPrime(10, 4, 1);
    result += testPrime(100, 25, 2);
    result += testPrime(1000, 168, 4);
    result += testPrime(10000, 1229, 8);
    result += testPrime(100000, 9592, 16);
    result += testPrime(1000000, 78498, 32);

    result += testTwinPrime(10, 2, 64);
    result += testTwinPrime(100, 8, 128);
    result += testTwinPrime(1000, 35, 256);
    result += testTwinPrime(10000, 205, 512);
    result += testTwinPrime(100000, 1224, 1024);
    result += testTwinPrime(1000000, 8169, 2048);


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
