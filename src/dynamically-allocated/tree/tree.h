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

#ifndef TREE_H
#define TREE_H

typedef struct node* BinaryTree;
typedef struct node  BTNode;

/**
 * @brief Initializes the binary tree structure.
 * @returns A pointer to a pointer root structure that represents the binary
 * tree.
 */
BinaryTree *btree_init();

/**
 * @brief Inserts a given node with a value v in an ordered way.
 * @param BinaryTree * The root of the tree.
 * @param int Represents the value of the new node
 * @returns An int representing the status of the insert; 1 for successfully
 * inserted nodes and 0 otherwise.
 */
int btree_insert(BinaryTree *, int);

/**
 * @brief
 * @param
 * @returns
 */
int btree_remove(BinaryTree *, int);

/**
 * @brief Removes a given node.
 * @param BTNode A pointer to a binary tree mode.
 * @returns The removed node.
 */
BTNode *btree_remove_node(BTNode *);

/**
 * @brief Count how many nodes there are in the binary tree.
 * @param BinaryTree *
 * @returns
 */
int btree_node_count(BinaryTree *, int acc);


/**
 * @brief
 * @param BinaryTree * The root of the binary tree.
 * @param int The value stored by the given node.

 * @returns A number representing if the value was found or not, true (1) if it
 * has found a value and false otherwise.
 */
int btree_node_exists(BinaryTree *, int);

/// Visualization tree algorightms

/**
 * @brief Prints the element in the order left, right, self.
 * @param BinaryTree the root of the BinaryTree.
 */
void postorder(BinaryTree *);

/**
 * @brief Prints the element in the order self, left, right.
 * @param BinaryTree the root of the BinaryTree.
 * @param int The level of the value that is being printed.
 */
void preorder(BinaryTree *, int);

/**
 * @brief Prints the element in the order left, self, right.
 * @param BinaryTree the root of the BinaryTree.
 */
void inorder(BinaryTree *);


#endif // TREE_H
