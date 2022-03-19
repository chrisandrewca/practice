// cl /Wall /WX /wd5045 /analyze /EHsc /TC /Zc:preprocessor clean-exit.c /Fo..\output\ /Fe..\output\ /link && ..\output\clean-exit.exe

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRERROR_BUF_SIZE 256
char strErrorBuf[STRERROR_BUF_SIZE] = { "\0" };

#define ERR_NO_MEM = 90000;

void onExit(void) {

    printf("Persisting state, closing connections, freeing memory...\n");
    printf("Logging errors...\n");

    // TODO locale
    errno_t e2 = strerror_s(strErrorBuf, STRERROR_BUF_SIZE, errno);

    printf("e1: %d, e2: %d, strerror: %s\n", e1, e2, strErrorBuf);

    printf("Goodbye!\n");
};

void main(void) {

    printf("Starting appp...\n");

    atexit(onExit);

    printf("Allocating memory...\n");
    printf("Oh no out of memory! Exiting w/ EXIT_FAILURE...\n");

    errno = ERR_NO_MEM;

    // abort(); will skip atexit functions...
    exit(EXIT_FAILURE);
};
