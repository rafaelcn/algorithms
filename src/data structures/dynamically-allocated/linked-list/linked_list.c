#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node *next;
    Type value;
};

static void pferror(char *m, int line) {
    fprintf(stderr, "\n\nError: %s | On line %d from file %s", m, line,
            __FILE__);
}

List *list_init(Type initial_value) {

    List *l = malloc(sizeof(List *));

    if (is_null(l)) {
        pferror("List allocation fails", __LINE__-3);
        exit(1);
    }

    l->next = NULL;
    l->value = initial_value;

    return l;
}

int list_push() {

}

int list_pop() {

}

void list_free(List *l) {
    while (!is_null(l->next)) {
        Node *e = l;

#ifdef DEBUG
        // this print depends on the type of the linked list element value.
        printf("\nCleaning element: %d", e->value);
#endif

        l = l->next;
        free(e);
    }

    free (l);
}

int is_null(void *p) {
    return p == NULL;
}
