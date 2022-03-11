typedef struct lnode lnode;

struct lnode {
    lnode* next;
    lnode* prev;
    void* data;
    size_t size;
};

lnode* ll_from_array(void *array, size_t type_size, size_t size);
// this is O(N) for each push...
void ll_push_back(lnode* head, void *data, size_t size);
// memory leak.. unless all these functions operate on a giant chunk
// of hosted memory
void ll_pop_front(lnode* head);
void ll_free(lnode* head);