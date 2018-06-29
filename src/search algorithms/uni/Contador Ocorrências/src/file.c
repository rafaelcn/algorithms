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

#include "file.h"

#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"
#include "iterator.h"

static void file_buffer_clean(char *buffer, size_t n) {

    for (size_t i = 0; i < n; i++) {
        buffer[i] = '\0';
    }
}

char *file_load(const char *filename) {

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "File %s couldn't be read\n\n", filename);
        exit(EXIT_FAILURE);
    }

    char *words = calloc(MAX_CHARS, sizeof(char));

    do {
        // FIXME: There is something wrong with this... It is reading the two
        // last characters from the last word repeatedly.
        fread(words, sizeof(char), MAX_CHARS, file);
    } while (!feof(file));

#ifdef DEBUG
    fprintf(stdout, "\nWORDS READ: %s\n\n", words);
#endif

    fclose(file);

    return words;
}

list_t *file_split_words(const char *filename) {

    list_t *words = NULL;
    char *file = file_load(filename);

    // a buffer  has at most sixty four characters for each word
    char buf[64];

    while (*file != '\0' && (int)*file != EOF) {
        // Internal counter
        int i = 0;
        // Clean the buffer everytime we loop
        file_buffer_clean(&buf[0], 64);

        while (isprint(*file) && !isspace(*file) && !isblank(*file) && i < 64) {
            buf[i] = *file;
            i++;
            file++;
        }

        words = list_push(words, buf);

        file++;
    }


#ifdef DEBUG
    iterator_t *it = iterator_new(words);

    printf("\nWORDS SPLIT:");

    while (iterator_next(it)) {
        printf("%s ", iterator_eval(it));
    }

    printf("\n\n");

    iterator_free(it);
#endif //DEBUG

    return words;
}
