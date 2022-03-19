// cl /Wall /WX /wd5045 /analyze /EHsc /TC /Zc:preprocessor barebones-exit.c /Fo..\output\ /Fe..\output\ /link && ..\output\barebones-exit.exe

#include <stdio.h>
#include <stdlib.h>

void onExit(void) {
    printf("onExit ~~ Goodbye!\n");
};

void main(void) {

    atexit(onExit);

    exit(EXIT_SUCCESS);
};
