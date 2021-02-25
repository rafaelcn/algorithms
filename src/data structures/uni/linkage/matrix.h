#ifndef MATRIX_H
#define MATRIX_H

#include <inttypes.h>

/**
 *
 * Assignment done under the Data Structures class in UTFPR.
 *
 * authors: Rafael Campos Nunes
 *          Mikael Messias
 *
 */


/**
 * @brief Typedefs to abstract the idea of a Matrix and a MatrixNode.
 */
typedef struct node* Matrix;
typedef struct node MatrixNode;

/**
 * @brief Initialises an MxN matrix and returns a pointer to the new
 * initialised matrix.
 * @param x Is the quantity of rows in the matrix.
 * @param y Is the quantity of columns in the matrix.
 */
Matrix *matrix_init(int x, int y);

/**
 * @brief Inserts a MatrixNode with the given value v at an x,y position.
 * @param m The Matrix to be inserted.
 * @param x The coordinate x to place the MatrixNode.
 * @param y The coordinate y to place the MatrixNode.
 * @param v The value to be inserted on the MatrixNode.
 */
int matrix_insert(Matrix *m, uint32_t x, uint32_t y, int v);

/**
 * @brief Removes the MatrixNode at an x,y position.
 * @param m A pointer to a MatrixNode.
 * @param x The coordinate x where the MatrixNode is.
 * @param y The coordinate y where the MatrixNode is.
 */
int matrix_remove_by_coordinate(Matrix *m, uint32_t x, uint32_t y);

/**
 * @brief Removes the MatrixNode with the given value v.
 * @param m A pointer to a MatrixNode.
 * @param v The value to be removed from the Matrix.
 */
int matrix_remove_by_value(Matrix *m, int v);

/**
 * @brief Searched for a MatrixNode on the coordinate x,y.
 * @param m The Matrix to be searched on.
 * @param x The coordinate x.
 * @param y The coordinate y.
 */
MatrixNode *matrix_get_by_coordinate(MatrixNode *m, uint32_t x, uint32_t y);

/**
 * @brief Searches for a MatrixNode with the given value v, if there is more
 * than one, it returns the first MatrixNode found.
 * @param m The Matrix to be searched on.
 * @param v The value to be used on search.
 * @returns A pointer to a MatrixNode or NULL on not found.
 */
MatrixNode *matrix_get_by_value(MatrixNode *m, int v);

/**
 * @brief It returns the value stored in a MatrixNode m.
 * @param m A pointer to a MatrixNode.
 * @returns An integer representing the value stored in the MatrixNode.
 */
int *matrix_get_value(MatrixNode *m);

/**
 * @brief Prints the matrix structure
 * @param m A pointer to the Matrix to be printed.
 * @returns 1 on success and 0 if it didn't succeed.
 */
int matrix_print(Matrix m);

/**
 * @brief Recursive function that prints information about each head of the
 * Matrix.
 * @param m The first Matrix head.
 */
void matrix_print_heads(MatrixNode *m);

/**
 * @brief Prints a MatrixNode.
 * @param m A pointer to the MatrixNode to be printed.
 * @returns 1 on success and 0 if it didn't succeed.
 */
int matrix_print_element(MatrixNode *m);

/**
 * @brief Print neighbours of an specific MatrixNode.
 * @param m The reference to be used when printing its neighbours.
 * @returns An integer representing whether or not it could print the
 * neighbours of the MatrixNode m.
 */
int matrix_print_neighbours(MatrixNode *m);

/**
 * @brief Frees the allocated Matrix.
 * @param m The matrix to be freed.
 */
void matrix_free(MatrixNode *m);


#endif // MATRIX_H
