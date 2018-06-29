/**
 *                Universidade Tecnológica Federal do Paraná
 *
 * Copyright (c) 2017 Rafael Nunes <rafaelnunes@engineer.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 */

#ifndef HASH_H
#define HASH_H

#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

#define HASH_MAX_SIZE 1003

struct hash_cell_s {
    // Number of words in the same entry (list)
    size_t count;
    // list of words that belongs to this key hash_cell
    list_t *word_list;
};


struct hashtable_s {
    // The total size of the hash table
    size_t size;
    // The amount of elements actually in the hash table
    size_t count;
    // The array of pointers to entries
    struct hash_cell_s **entries;
};

typedef struct hash_cell_s hash_cell_t;
typedef struct hashtable_s hashtable_t;

/**
 * @brief
 */
hashtable_t *ht_init();
/**
 * @brief
 */
void ht_insert(hashtable_t *, const char *);
/**
 * @brief
 */
hash_cell_t *ht_search(hashtable_t *, const char *);
/**
 * @brief
 */
void ht_free(hashtable_t *);

#endif // HASH_H
