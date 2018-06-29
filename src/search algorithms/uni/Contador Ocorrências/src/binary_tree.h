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

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct binary_tree_s {
    char word[64];
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/**
 * @brief Initialize the binary tree and returns a pointer to the root of the
 * tree
 */
binary_tree_t *bst_init(const char *);
/**
 * @brief Pushes a value (word) to the binary tree
 */
binary_tree_t *bst_push(binary_tree_t *, const char *);
/**
 * @brief Returns the word belonging to the pointer to the root passed for this
 * function.
 */
const char *bst_value(binary_tree_t*);
/**
 * @brief
 */
void bst_inorder(binary_tree_t *);
/**
 * @brief Frees the binary tree
 */
void bst_free(binary_tree_t *);



#endif // BINARY_TREE
