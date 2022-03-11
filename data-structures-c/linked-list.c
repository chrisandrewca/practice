#include "linked-list.h"
#include <stdlib.h>
#include <string.h>

lnode* ll_from_array(void *array, size_t type_size, size_t size) {

    // I really wanted to use a giant chunk of mem but...
    // then we need to do realloc or windows/views once we pop_front/remove
    // lnode *list = (lnode *) calloc(sizeof(lnode) * size);

    void *data = (void *)calloc(1, sizeof(type_size));
    lnode *head = (lnode *)calloc(1, sizeof(lnode));

    // user has to push data because they have the type
    // so we can technically alloc
    // then they set *void = int?
    // ...c only the caller knows the type here so not even worthwile to make generic?
    // OR MACRO LOL
    memcpy(data, array[0], type_size);
    *head = lnode{
        NULL,
        NULL,
        data,
        type_size
    };

    lnode *prev = head;
    for (size_t i = 1; i < size; i++) {

        void *data = (void *)calloc(1, type_size);
        *data = *(array + i);

        lnode *next = (lnode *)calloc(1, sizeof(lnode));
        *next = lnode{
            NULL,
            prev,
            data,
            type_size
        };

        prev->next = next;
        prev = next;
    }

    head->prev = prev;
    prev->next = head;

    return head;
};

// this is O(N) for each push...
void ll_push_back(lnode* head, void *data, size_t size) {
};

// memory leak.. unless all these functions operate on a giant chunk
// of hosted memory
void ll_pop_front(lnode* head) {
};

void ll_free(lnode* head) {
};
