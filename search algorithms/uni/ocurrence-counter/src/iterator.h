#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>
#include <stddef.h>

// This is a linked list iterator
#include "linked_list.h"

#define ERR001 "Null pointer"
#define ERR002 "Could not allocate memory"

//
typedef struct iterator iterator_t;

/**
 * @brief Constructs a new iterator from the list and returns a pointer to the
 * newly created iterator.
 */
iterator_t *iterator_new(list_t *);
/**
 * @brief Free a created iterator.
 */
void iterator_free(iterator_t *);
/**
 * @brief Resets the iterator to its begin position.
 */
void iterator_reset(iterator_t *);
/**
 * @brief Returns the size of the underlying list.
 */
size_t iterator_size(iterator_t *);
/**
 * @brief A method that returns true if it has another element on the list or
 * false otherwise, in addition to that it also goes forward on the list as it
 * iterates if the true statement is verified. It does not modify the
 * pointer passed as parameter to the method.
 */
bool iterator_next(iterator_t const *);
/**
 * @brief Evaluates the value of the current iterator and if there is a next
 * node from the iterator it goes to the next.
 */
char *iterator_eval(iterator_t *);



#endif // ITERATOR_H
