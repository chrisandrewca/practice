#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void onExit() {

    printf("Printing strerror...\n");

    char buf[256] = { "\0" };
    errno_t strErrorCode = strerror_s(buf, 256, errno);

    printf("%u?, %u?, %s\n", errno, strErrorCode, buf);

    // Exit
};

void main(void) {
    atExit(onExit);

    //EXIT?
};
