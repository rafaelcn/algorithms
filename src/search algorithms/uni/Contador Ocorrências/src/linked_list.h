#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_s list_t; // an abstraction of a list

/**
 * @brief
 */
list_t *list_init();
/**
 * @brief Pushes a node to the list
 */
list_t *list_push(list_t *, char *);
/**
 * @brief Finds a specific word in the list and returns a pointer to it. The
 * node isn't supposed to be changed.
 */
const list_t *list_search(list_t *, char *);



#endif // LINKED_LIST_H
