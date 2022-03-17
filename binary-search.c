// cl /Wall /WX /wd5045 /analyze /EHsc /TC /Zc:preprocessor binary-search.c /Fo.\output\ /Fe.\output\ /link && .\output\binary-search.exe

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool binarySearch(
    void* array,
    size_t arraySize,
    size_t elementSize,
    void* value,
    int (*valueLessThanGreaterOrEqualToElement)(void*, void*),
    size_t* valueIndex) {

    size_t min = 0;
    size_t max = arraySize - 1;
    size_t i = 0;

    char* basePtr = (char*)array;
    char* elementPtr = NULL;

    while (min <= max) {

        i = (min + max) / 2;

        elementPtr = basePtr + (i * elementSize);

        int order = valueLessThanGreaterOrEqualToElement(value, (void*)elementPtr);

        if (order < 0) {

            if (i == 0) {
                return false;
            }

            max = i - 1;
        } else if (order > 0) {

            min = i + 1;
        } else {

            *valueIndex = i;
            return true;
        }
    }

    return false;
};

int bsCompareIntValue(void* valuePtr, void* elementPtr) {

    int value = *((int*)valuePtr);
    int element = *((int*)elementPtr);

    if (value < element) {
        return -1;
    } else if (value > element) {
        return 1;
    }

    return 0;
}

void main(void) {

    #define PRIMES_SIZE 25

    int primes[PRIMES_SIZE] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
        41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
    };

    int searchValue = 7;
    size_t index = 0;

    bool found = binarySearch(
        (void*)primes,
        PRIMES_SIZE,
        sizeof(int),
        (void*)&searchValue,
        &bsCompareIntValue,
        &index);

    printf("value: %d, found: %d, index: %zd\n", searchValue, found, index);

    searchValue = 89;
    index = 0;

    found = binarySearch(
        (void*)primes,
        PRIMES_SIZE,
        sizeof(int),
        (void*)&searchValue,
        &bsCompareIntValue,
        &index);

    printf("value: %d, found: %d, index: %zd\n", searchValue, found, index);

    searchValue = -2;
    index = 0;

    found = binarySearch(
        (void*)primes,
        PRIMES_SIZE,
        sizeof(int),
        (void*)&searchValue,
        &bsCompareIntValue,
        &index);

    printf("value: %d, found: %d, index: %zd\n", searchValue, found, index);

    return;
};
