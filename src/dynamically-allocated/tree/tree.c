/**
 * MIT License
 *
 * Copyright (c) 2017 Rafael C. Nunes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE  SOFTWARE.
 */

#include "tree.h"

#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

static void
pferror(char *m, int line) {
    fprintf(stderr, "\n>> %s | File: %s on line %d.\n", m, __FILE__, line);
}

static int
check_pointer(void *p) {
    if (p != NULL) {
        return 1;
    }

    return 0;
}

BinaryTree *
btree_init() {
    BinaryTree *bt = malloc(sizeof(struct node));

    if (bt == NULL) {
        pferror("Tree root couldn't be created", __LINE__);
        exit(1);
    } else {
        *bt = NULL;
    }

    return bt;
}

int
btree_insert(BinaryTree *root, int v) {
#ifdef DEBUG
    printf("Creating node %d\n", v);
#endif

    if (root != NULL) {
        BTNode *n = malloc(sizeof(BTNode));

        if (check_pointer(n)) {
            n->data = v;
            n->left = NULL;
            n->right = NULL;

            if (check_pointer(*root)) {
                BTNode *walker = *root;
                BTNode *walkerp = NULL;

                while (walker != NULL)  {
                    walkerp = walker;

                    if (walker->data == v) {
                        // Element already exists
                        free(n);
                        return 0;
                    }

                    if (v > walker->data) {
                        walker = walker->right;
                    } else {
                        walker = walker->left;
                    }
                }

                if (v > walkerp->data) {
                    walkerp->right = n;
                } else {
                    walkerp->left = n;
                }
            } else {
                *root = n;
                return 1;
            }

        } else {
            pferror("Couldn't allocate a tree node", __LINE__);
            return 0;
        }
    }

    pferror("Argument given to btree_insert is null", __LINE__);
    return 0;
}

int
btree_remove(BinaryTree *root, int v) {
    if (check_pointer(root)) {
        BTNode *walker = *root;
        BTNode *walkerp = NULL;

        while (walker != NULL) {
            if (walker->data == v) {
                if (walker == *root) {
                    // The value to be removed is the root!
                    btree_remove_node(walker);
                } else {
                    if (walkerp == walker) {
                        walkerp->right = btree_remove_node(walker);
                    } else {
                        walkerp->left = btree_remove_node(walker);
                    }
                }
                return 1;
            }
            walkerp = walker;
            if (v > walker->right->data) {
                walker = walker->right;
            } else {
                walker = walker->left;
            }
        }
    }

    pferror("Argument given to btree_remove is null", __LINE__);
    return 0;
}

int
btree_node_count(BinaryTree *root, int acc) {
    // FIXME: Doesn't count correctly
    if (check_pointer((*root)->left)) {
        btree_node_count(&(*root)->left, acc+1);
    }

    if (check_pointer((*root)->right)) {
        btree_node_count(&(*root)->right, acc+1);
    }

    return acc;
}

BTNode *
btree_remove_node(BTNode *no) {
    BTNode *node, *node1;

    if (no->left == NULL) {
        node1 = no->right;
        free(no);
        return node1;
    }

    node = no;
    node1 = no->left;

    while (node1->right != NULL) {
        node = node1;
        node1 = node1->right;
    }

    if (node != no) {
        node->right = node1->left;
        node1->left = no->left;
    }

    node1->right = no->right;
    free(no);

    return node1;
}

int
btree_node_exists(BinaryTree *root, int v) {
    if (check_pointer(root)) {
        if ((*root)->data == v) {
            return 1;
        }

        if ((*root)->data < v) {
            btree_node_exists(&(*root)->right, v);
        } else {
            btree_node_exists(&(*root)->left, v);
        }
    }

    return 0;
}

void
btree_free(BinaryTree *root) {
    if (*root != NULL) {

    }
}


void
postorder(BinaryTree *root) {
    if (root == NULL) {
        return;
    }

    postorder(&((*root)->left));
    postorder(&((*root)->right));
    printf("%d\n", (*root)->data);
}


void
preorder(BinaryTree *root, int n) {
    if (root == NULL) {
        return;
    }

    if (*root != NULL) {
        printf("|");

        for (int i = 0; i < n; i++) {
            printf("_");
        }

        printf("%d\n", (*root)->data);
        preorder(&((*root)->left), n+1);
        preorder(&((*root)->right), n+1);
    }
}

void
inorder(BinaryTree *root) {
    if (root == NULL) {
        return;
    }

    inorder(&((*root)->left));
    printf("%d\n", (*root)->data);
    inorder(&((*root)->right));
}
