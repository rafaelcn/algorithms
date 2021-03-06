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
#include <assert.h>
#include <string.h>

#include "../linked_list.h"
#include "../iterator.h"

struct list_s {
    char value[64];
    struct list_s *next;
};

typedef struct list_s list_t;

int main(int argc, char **argv) {

    list_t *list = NULL;
    list = list_push(list_push(list_push(list_push(list, "something"), "campos"), "nunes"),
                     "rafael");

    iterator_t *it = iterator_new(list);

    char *words[4];
    words[0] = "something";
    words[1] = "campos";
    words[2] = "nunes";
    words[3] = "rafael";

    size_t i = 0;

    while (iterator_next(it)) {
        char *word = iterator_eval(it);

        assert(strcmp(words[i], word) == 0);

        printf("%s\n", word);
        i++;
    }

    return 0;
}
