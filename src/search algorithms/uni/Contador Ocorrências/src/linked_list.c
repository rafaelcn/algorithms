#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list_s {
    char value[64];
    struct list *next;
};

list_t *list_init(char *value) {

    list_t *l = malloc(sizeof(list_t));

    if (l == NULL) {
        fprintf(stderr, "ERR: The list couldn't be created\n");
        exit(EXIT_FAILURE);
    }

    strcpy(l->value, value);
    l->next = NULL;

    return l;
}

list_t *list_push(list_t *l, char *value) {

    if (l == NULL) {
        l = list_init(value);
        return l;
    }

    while (l->next != NULL) {
        l = l->next;
    }

    node_t *e = malloc(sizeof(node_t));

    strcpy(e->value, value);
    e->next = NULL;

    l->next = e;

    return l;
}

node_t *list_search(list_t *l, char *value) {

    if (l == NULL) {
        fprintf(stdout, "WARN: Can't find any value on an empty list.\n");
        return NULL;
    }

    while (l->next != NULL) {
        if (strcmp(l->value, value) == 0) {
            return l;
        }

        l = l->next;
    }

    return NULL;
}
