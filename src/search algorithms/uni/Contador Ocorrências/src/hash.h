#ifndef HASH_H
#define HASH_H

#include "linked_list.h"

struct cell_s {
    int count;
    list_t *values;
};

struct hashtable_s {
    int size;
    struct cell_s **entries;
};

typedef struct cell_s cell_t;
typedef struct hashtable_s hashtable_t;

#endif // HASH_H
