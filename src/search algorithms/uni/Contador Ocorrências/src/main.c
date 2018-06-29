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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "hash.h"
#include "iterator.h"
#include "linked_list.h"
#include "macros.h"

void usage();

int main(int argc, char **argv) {

    if (argc <= 1) {
        usage();
        exit(0);
    }

    // The name of the file to be loaded
    char *filename = argv[1];
    // The list of words read by the file
    list_t* words_list = file_split_words(filename);
    // Creating an iterator for the list of words
    iterator_t *it = iterator_new(words_list);

    hashtable_t *ht = ht_init();

    while (iterator_next(it)) {
        char *word = iterator_eval(it);
        ht_insert(ht, word);
    }

#ifdef DEBUG
    printf("\nWORDS READ: %zu\n", iterator_size(it));
#endif // DEBUG

    for (int i = 0; i < HASH_MAX_SIZE; i++) {
        if (ht->entries[i] != NULL) {
            const char *word = list_head(ht->entries[i]->word_list);

            if (ht->entries[i]->count >= 3 && strlen(word) >= 3) {
                printf("%-15s  %zu\n", word, ht->entries[i]->count);
            }
        }
    }

    iterator_free(it);
    list_free(words_list);
    ht_free(ht);

    return 0;
}


void usage() {

    char exec_name[12] = "counter";
    char *extension = ".out";

#ifdef __WIN32
    extension = ".exe";
#endif

    strcat(exec_name, extension);
    printf("Usage: %s <file.txt>\n", exec_name);
}
