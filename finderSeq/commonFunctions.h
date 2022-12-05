#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H

#include <stdlib.h>

void siegeOfEratosthenes(char* array, int n);
void* allocateMemory(size_t size);
void populateArray(char* array, int n);
int countPrimeNumbers(const char* array, int n);
void printPrimeNumbers(const char* array, int n);
int countTwinPrimeNumbers(const char* array, int n);
void printTwinPrimeNumbers(const char* array, int n);

#endif
