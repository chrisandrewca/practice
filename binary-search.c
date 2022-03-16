// cl /Wall /WX /wd5045 /analyze /EHsc /TC /Zc:preprocessor binary-search.c /Fo.\output\ /Fe.\output\ /link && .\output\binary-search.exe

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

bool binarySearch(int* nums, size_t numsSize, int value, size_t* valueIndex) {

    size_t min = 0;
    size_t max = numsSize - 1;
    size_t i = 0;
    
    while (min <= max) {
        
        i = (min + max) / 2;

        if (value < nums[i]) {
            
            if (i == 0) {
                return false;
            }

            max = i - 1;
        } else if (value > nums[i]) {

            min = i + 1;
        } else if (value == nums[i]) {
            
            *valueIndex = i;
            return true;
        }
    }
    
    return false;
};

void main(void) {

    #define PRIMES_SIZE 25

    int primes[PRIMES_SIZE] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
        41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
    };

    size_t index = 0;
    bool found = binarySearch(primes, PRIMES_SIZE, 7, &index);
    printf("value: %d, found: %d, index: %zd\n", 7, found, index);

    index = 0;
    found = binarySearch(primes, PRIMES_SIZE, 89, &index);
    printf("value: %d, found: %d, index: %zd\n", 89, found, index);

    index = 0;
    found = binarySearch(primes, PRIMES_SIZE, -2, &index);
    printf("value: %d, found: %d, index: %zd\n", -2, found, index);

    return;
};
