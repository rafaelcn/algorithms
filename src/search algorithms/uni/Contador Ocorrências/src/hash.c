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

#include "hash.h"

#include "utils.h"
#include "linked_list.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * My implementation of the POSIX function strdup.
 *
 * @brief returns a pointer to an array of chars (string)
 */
static char *strdup(const char *src) {

    char *dst = NULL;
    char *p;
    int len = strlen(src);

    dst = calloc(len + 1, sizeof *dst);

    p = dst;

    while (*src) {
        *p++ = *src++;
    }

    *p = '\0';

    return dst;
}

static hash_cell_t* ht_new_hash_cell(const char *word)  {

    hash_cell_t* hash_cell = malloc(sizeof *hash_cell);

    if (hash_cell == NULL) {
        error("Allocating a new cell has failed", __FILE__, __LINE__);
    }

    hash_cell->count = 1;
    hash_cell->word_list = list_init(word);

    return hash_cell;
}

static void ht_del_hash_cell(hash_cell_t *cell) {

    list_free(cell->word_list);
    free(cell);
}

static int ht_hash(const char *word) {
    //  https://github.com/jamesroutley/write-a-hash-table/tree/master/03-hashing
    // Slightly modified.
    long hash = 0;
    size_t len = strlen(word);

    for (size_t i = 0; i < len; i++) {
        hash = (long)pow(137, len - (i+1)) * word[i];
        hash = hash % HASH_MAX_SIZE;
    }

    return (int)hash;
}

static int ht_hash2(const char *word) {
    // This is authory of Rafael Campos Nunes
    long hash = 0;
    size_t len = strlen(word);

    for (size_t i = 0; i < len; i++) {
        hash += word[i] * 137 - i;
    }

    hash = hash % HASH_MAX_SIZE;
    return (int)hash;
}

hashtable_t *ht_init() {

    hashtable_t *hash_table = malloc(sizeof *hash_table);

    if (hash_table == NULL) {
        error("Allocation of the hash table has failed.", __FILE__,
              __LINE__-3);
    }

    // Starting the size of the hash with the maximum amount of elements
    // possible.
    hash_table->size = HASH_MAX_SIZE;
    // The table of entries being allocated.
    hash_table->entries = calloc(hash_table->size, sizeof(hash_cell_t*));

    return hash_table;
}



void ht_insert(hashtable_t *ht, const char *word) {

    if (ht == NULL) {
        error("Hash table structure is nill", __FILE__, __LINE__-3);
        return;
    }

    // The hash key for the word.
    int hashed = ht_hash2(word);
    // This might return NULL, careful.
    hash_cell_t *cell = ht_search(ht, word);

#ifdef DEBUG
    printf("\nINSERTING \"%s\". HASH VALUE: \"%d\"", word, hashed);
#endif // DEBUG

    if (cell == NULL) {
        cell = ht_new_hash_cell(word);
        ht->entries[hashed] = cell;
    } else {
        ht->entries[hashed]->count++;
        ht->entries[hashed]->word_list =
            list_push(ht->entries[hashed]->word_list, word);
    }
}

hash_cell_t *ht_search(hashtable_t *ht, const char *word) {

    if (ht == NULL) {
        error("Hash table structure is nill", __FILE__, __LINE__-3);
        return NULL;
    }

    return ht->entries[ht_hash2(word)];
}

void ht_free(hashtable_t *ht) {

    for (size_t i = 0; i < ht->size; i++) {
        if (ht->entries[i] != NULL) {
            ht_del_hash_cell(ht->entries[i]);
        }
    }

    free(ht->entries);
    free(ht);
}
