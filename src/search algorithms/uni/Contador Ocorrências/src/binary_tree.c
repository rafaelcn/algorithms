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

#include "binary_tree.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

binary_tree_t *bst_init(const char *word) {

    binary_tree_t *r = malloc(sizeof *r);

    if (!r) {
        error("Allocation of the tree has failed", __FILE__, __LINE__-3);
        exit(1);
    }

    r->left = NULL;
    r->right = NULL;

    strcpy(r->word, word);

    return r;
}

binary_tree_t *bst_push(binary_tree_t *r, const char *word) {

    if (!r) {
        binary_tree_t *t = malloc(sizeof *t);

        t->left = NULL;
        t->right = NULL;

        strcpy(t->word, word);

        return t;
    }

    if (strcmp(r->word, word) > 0) {
        r->left = bst_push(r->left, word);
    } else if (strcmp(r->word, word) < 0) {
        r->right = bst_push(r->right, word);
    }

    return r;
}

const char *bst_value(binary_tree_t *r) {

    if (r) {
        return r->word;
    }

    error("Trying to get the word of a null tree", __FILE__, __LINE__);
    return NULL;
}

void bst_inorder(binary_tree_t *r) {

    if (r) {
        bst_inorder(r->left);
        printf("%s\n", r->word);
        bst_inorder(r->right);
    }
}

void bst_free(binary_tree_t *r) {

    if (r->left) {
        bst_free(r->left);
    } else if (r->right) {
        bst_free(r->right);
    } else {
        free(r);
    }
}
