#ifndef _CC_LIB_H_
#define _CC_LIB_H_

#include <errno.h>
#include <stdlib.h>
#include <string.h>

// TODO static error strings with
// setlocale(LC_ALL, "ja_JP.utf8");
#define ERR_NO_MEM 90000

#define callocOf(count, type, address) {\
    *address = (type*)calloc(count, sizeof(type));\
    if (NULL == *address) {\
        errno = ERR_NO_MEM;\
        exit(ERR_NO_MEM);\
    }\
};

// TODO synchronization across threads/process
// so errors don't step on each other
#define STRERROR_BUF_SIZE 256
char strErrorBuf[STRERROR_BUF_SIZE] = { '\0' }; // inspect this

// TODO synchronization across threads/process
// so errors don't step on each other
errno_t captureStrError(void) {
    return strerror_s(strErrorBuf, STRERROR_BUF_SIZE, errno);
};

void clearStrError(void) {
    memset(strErrorBuf, 0, STRERROR_BUF_SIZE);
    strErrorBuf[0] = '\0';
};

void setOnExit(void (*onExit)(void)) {
    atexit(onExit);
};

#endif
