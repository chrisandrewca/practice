/*
    cl /W4 /EHsc ^
        /I .\data-structures-c ^
        breadth-first-search.c ^
        .\data-structures-c\linked-list.c ^
        /Fo.\output\ /Fe.\output\ /link && .\output\breadth-first-search.exe
*/
#include "linked-list.h"
#include <stdio.h>

void main() {

    int a = 0;
    ll_free(&a);
    printf("hello, world");
};
