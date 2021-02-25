#include "iterator.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct iterator {
    size_t size;
    list_t *begin;
    list_t *end;
    list_t *list;
};

// Like a forward declaration, a better solution should be provided later
struct list_s {
    char value[64];
    struct list_s* next;
};

iterator_t *iterator_new(list_t *l) {

    if (l == NULL) {
        fprintf(stderr, "Error creating the iterator, see ERR001.\n");
        return NULL;
    }

    iterator_t *it = malloc(sizeof(iterator_t));

    if (it == NULL) {
        fprintf(stderr, "Error creating the iterator, see ERR002.\n");
    }

    it->list = l;
    it->begin = l;

    it->size = 0;

    while (l->next != NULL) {
        it->size++;
        l = l->next;
    }

    it->end = l;

    return it;
}


void iterator_free(iterator_t *it) {
    free(it);
}

void iterator_reset(iterator_t *it) {

    it->list = it->begin;
}

size_t iterator_size(iterator_t* it) {

    return it->size;
}

bool iterator_next(iterator_t const *it) {

    if (it == NULL) {
        fprintf(stderr, "Error trying to evaluate the iterator, see ERR001.\n");
        return false;
    }

    if (it->list == NULL) {
        return false;
    }

    return true;
}

char *iterator_eval(iterator_t *it) {

    if (it == NULL) {
        fprintf(stderr, "Error evaluating the iterator, see ERR001. Aborting.\n");
        exit(1);
    }

    if (it->list == NULL) {
        fprintf(stderr, "The iterator is ill constructed, construct it again\n");
    }

    char *ret = it->list->value;

    it->list = it->list->next;

    return ret;
}
