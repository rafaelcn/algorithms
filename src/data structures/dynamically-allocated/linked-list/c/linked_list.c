/**
 * MIT License
 *
 * Copyright (c) 2017 Rafael C. Nunes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE  SOFTWARE.
 */

#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node *next;
    Type value;
};

static int is_null(void *);

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

List *list_push(List *l, int v) {

    if (is_null(l)) {
        pferror("", __LINE__);
        return l;
    }

    List *tmp = l;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    List *e = malloc(sizeof(List));

    if (is_null(e)) {
        pferror("Couldn't allocate a node for the list", __LINE__-3);
        return l;
    }

    e->next = NULL;
    e->value = v;

    tmp->next = e;

    return l;
}

Node *list_pop(List *l) {

    if (is_null(l)) {
        pferror("", __LINE__);
        return l;
    }

    List *tmp = l->next;
    List *previous = l;

    while (tmp->next != NULL) {
        previous = tmp;
        tmp = tmp->next;
    }

    previous->next = NULL;

    return tmp;
}

List *list_remove(List *l, int v) {

    if (is_null(l)) {
        pferror("The list is null", __LINE__);
        return l;
    }

    // There's the Linus way but I'm fond with this as it is easier to be read
    // by beginners.
    List *tmp = l->next;
    List *previous = l;

    while (tmp->next != NULL && tmp->value != v) {
        previous = tmp;
        tmp = tmp->next;
    }

    previous->next = tmp->next;

    free(tmp);

    return l;
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

static int is_null(void *p) {
    return p == NULL;
}
