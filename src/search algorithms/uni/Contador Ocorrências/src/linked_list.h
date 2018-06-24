#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_s list_t; // an abstraction of a list
typedef struct list_s node_t; // an abstraction of a node

/**
 *
 */
list_t *list_init();
/**
 *
 */
list_t *list_push(list_t *, char *);
/**
 *
 */
node_t *list_search(list_t *, char *);

#endif // LINKED_LIST_H
