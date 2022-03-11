// cl /W4 /EHsc merge-sort.c /Fo.\output\ /Fe.\output\ /link && .\output\merge-sort.exe

#include <stdlib.h>
#include <stdio.h>


void merge(int array[], int p, int q, int r);

void mergeSort(int array[], int p, int r) {

    if (p < r) {

        int q = (p + r) / 2;

        mergeSort(array, p, q);
        mergeSort(array, q + 1, r);
        merge(array, p, q, r);
    }
};

// we can avoid allocating inside a hot loop with static arrays of size N
// which get cleared
void merge(int array[], int p, int q, int r) {

    int lowLength = q - p + 1;
    int highLength = r - q;

    int* lowHalf = malloc(sizeof(int) * lowLength);
    int* highHalf = malloc(sizeof(int) * highLength);

    int i = 0, j = 0, k = p;

    for (; k <= q; i++, k++) {
        lowHalf[i] = array[k];
    }

    for (; k <= r; j++, k++) {
        highHalf[j] = array[k];
    }

    i = 0;
    j = 0;
    k = p;

    while (i < lowLength && j < highLength) {

        if (lowHalf[i] <= highHalf[j]) {
            array[k] = lowHalf[i];
            i++;
        } else {
            array[k] = highHalf[j];
            j++;
        }

        k++;
    }

    while (i < lowLength) {
        array[k] = lowHalf[i];
        i++;
        k++;
    }

    while (j < highLength) {
        array[k] = highHalf[j];
        j++;
        k++;
    }

    free(lowHalf);
    free(highHalf);
};

void main() {

    int array[] = { 3, 7, 12, 14, 2, 6, 9, 11 };
    printf("array: ");
    for (int i = 0; i < (sizeof array / sizeof *array); i++) { printf("%d, ", array[i]); }
    printf("\n");
    mergeSort(array, 0, (sizeof array / sizeof *array) - 1);
    printf("sorted: ");
    for (int i = 0; i < (sizeof array / sizeof *array); i++) { printf("%d, ", array[i]); }
    printf("\n");

    int array2[] = { 99, 97, -3, -55, -6, 7, 8, 14, 31, 32, -0, 0, 3, 2 };
    printf("array: ");
    for (int i = 0; i < (sizeof array2 / sizeof *array2); i++) { printf("%d, ", array2[i]); }
    printf("\n");
    mergeSort(array2, 0, (sizeof array2 / sizeof *array2) - 1);
    printf("sorted: ");
    for (int i = 0; i < (sizeof array2 / sizeof *array2); i++) { printf("%d, ", array2[i]); }
    printf("\n");
};