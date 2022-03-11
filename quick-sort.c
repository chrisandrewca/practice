// cl /W4 /EHsc quick-sort.c /Fo.\output\ /Fe.\output\ /link && .\output\quick-sort.exe
#include <stdlib.h>
#include <stdio.h>

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
};

int partition(int array[], int p, int r) {

    int q = p;

    for (int j = p; j <= r - 1; j++) {
        if (array[j] <= array[r]) {
            swap(array, j, q);
            q++;
        }
    }

    swap(array, r, q);
    return q;
};

void quickSort(int array[], int p, int r) {

    if (p < r) {

        int q = partition(array, p, r);

        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}

void main() {

    int array[] = { 3, 7, 12, 14, 2, 6, 9, 11 };
    printf("array: ");
    for (int i = 0; i < (sizeof array / sizeof *array); i++) { printf("%d, ", array[i]); }
    printf("\n");
    quickSort(array, 0, (sizeof array / sizeof *array) - 1);
    printf("sorted: ");
    for (int i = 0; i < (sizeof array / sizeof *array); i++) { printf("%d, ", array[i]); }
    printf("\n");

    int array2[] = { 99, 97, -3, -55, -6, 7, 8, 14, 31, 32, -0, 0, 3, 2 };
    printf("array: ");
    for (int i = 0; i < (sizeof array2 / sizeof *array2); i++) { printf("%d, ", array2[i]); }
    printf("\n");
    quickSort(array2, 0, (sizeof array2 / sizeof *array2) - 1);
    printf("sorted: ");
    for (int i = 0; i < (sizeof array2 / sizeof *array2); i++) { printf("%d, ", array2[i]); }
    printf("\n");
};