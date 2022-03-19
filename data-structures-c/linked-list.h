#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include "cclib.h"
#include <stdio.h>

struct linkedListNode {
    void* value;
    size_t typeSize;
    struct linkedListNode* next;
    struct linkedListNode* prev;
};

struct linkedList {
    struct linkedListNode* head;
    size_t size;
};

struct linkedList* linkedList(void) {

    struct linkedList* list = NULL;
    callocOf(1, struct linkedList, &list);

    return list;
};

void freeLinkedList(
    struct linkedList* list,
    void (*freeNodeValue)(struct linkedListNode*)) {

    if (list->head == list->head->next) {

        freeNodeValue(list->head);
        free(list->head);
        free(list);

    } else {

        // snap the circle to form a line
        list->head->prev->next = NULL;

        struct linkedListNode* node = list->head;
        struct linkedListNode* next = NULL;

        do {

            next = node->next;
            freeNodeValue(node->value);
            free(node);
            node = next;

        } while(node != NULL);

        free(list);
    }
};

struct linkedListNode* linkedListNode(
    struct linkedList* list,
    void* value,
    size_t typeSize) {

    struct linkedListNode* listNode = NULL;
    callocOf(1, struct linkedListNode, &listNode);
    
    listNode->value = value;
    listNode->typeSize = typeSize;

    if (list->head != NULL) {

        struct linkedListNode* tail = list->head->prev;
        tail->next = listNode;
        listNode->prev = tail;

        listNode->next = list->head;
        list->head->prev = listNode;

        if (list->head->next == list->head) {
            list->head->next = listNode;
        }
    } else {

        listNode->next = listNode;
        listNode->prev = listNode;
        list->head = listNode;
    }

    return listNode;
};

#endif
