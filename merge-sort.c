// cl /Wall /WX /wd5045 /analyze /EHsc /TC /Zc:preprocessor merge-sort.c /Fo.\output\ /Fe.\output\ /link && .\output\merge-sort.exe

#include <stdlib.h>
#include <stdio.h>

void _mergeSort(int* array, const size_t low, const size_t high) {

    if (high <= low) {
        return;
    }

    size_t mid = (low + high) / 2;

    _mergeSort(array, low, mid);
    _mergeSort(array, mid + 1, high);

    int* sorted = (int*)calloc(
        (mid - low + 1)     // lower length
        + (high - mid)      // higher length
        , sizeof(int));
    
    if (NULL == sorted) {
        return; // TODO jmp? sig handler?
    }

    // considering lengths above
    // and low and mid + 1 here
    // I wonder how many popular merge sorts out there have
    // out of bounds access issues
    // I think the Khan Academy implementation has an OOB re: leetcode two-sum
    size_t i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {

        if (array[i] <= array[j]) {
            sorted[k] = array[i];
            i++;
        } else {
            sorted[k] = array[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        sorted[k] = array[i];
        i++;
        k++;
    }

    while (j <= high) {
        sorted[k] = array[j];
        j++;
        k++;
    }

    for (i = 0, k = low; k <= high; ++i, ++k) {
        array[k] = sorted[i];
    }

    free(sorted);
};

// we can avoid allocating inside a hot loop with static arrays of size N
// which get cleared
// aka initialize our version of the "C runtime" in a biggger app
void mergeSort(int* array, size_t size) {

    _mergeSort(array, 0, size - 1);
};

void main(void) {

    int array[] = { 3, 7, 12, 14, 2, 6, 9, 11 };
    printf("array: ");
    for (int i = 0; i < (sizeof array / sizeof *array); i++) { printf("%d, ", array[i]); }
    printf("\n");
    mergeSort(array, (sizeof array / sizeof *array));
    printf("sorted: ");
    for (int i = 0; i < (sizeof array / sizeof *array); i++) { printf("%d, ", array[i]); }
    printf("\n");

    int array2[] = { 99, 97, -3, -55, -6, 7, 8, 14, 31, 32, -0, 0, 3, 2 };
    printf("array: ");
    for (int i = 0; i < (sizeof array2 / sizeof *array2); i++) { printf("%d, ", array2[i]); }
    printf("\n");
    mergeSort(array2, (sizeof array2 / sizeof *array2));
    printf("sorted: ");
    for (int i = 0; i < (sizeof array2 / sizeof *array2); i++) { printf("%d, ", array2[i]); }
    printf("\n");
};
