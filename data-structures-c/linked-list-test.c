/*
cl /Wall /WX ^
    /wd5045 /wd4820 ^
    /analyze /EHsc /TC /Zc:preprocessor ^
    /I.\ ^
    /I..\ ^
    linked-list-test.c ^
    /Fo..\output\ /Fe..\output\ /link && ..\output\linked-list-test.exe
*/

#include "cclib.h"
#include "linked-list.h"
#include <stdio.h>

struct user {
    int id;
    char* name;
};

void freeLinkedListNodeOfUser(struct linkedListNode* node) {

    struct user* user = (struct user*)node->value;

    free(user->name);
};

void onExit(void) {
    errno_t errnum = captureStrError();
    printf("Error: %d, %s\n", errnum, strErrorBuf);
};

void main(void) {

    setOnExit(onExit);

    struct linkedList* list = NULL;
    callocOf(1, struct linkedList, &list);
    printf("listPtr: %p\n", list);

    struct user* user = NULL;
    callocOf(1, struct user, &user);

    user->id = 23;
    callocOf(30, char, &user->name);
    strncpy_s(user->name, 30, "Christopher", 11);

    struct linkedListNode* node
        = linkedListNode(list, (void*)user, sizeof(struct user));

    user = (struct user*)node->value;
    printf("id: %d, name: %s\n", user->id, user->name);

    node = list->head;
    do {

        user = (struct user*)node->value;
        printf("id: %d, name: %s\n", user->id, user->name);

        node = node->next;

    } while(node != list->head);

    freeLinkedList(list, freeLinkedListNodeOfUser);

    printf("Finished.\n");
};
