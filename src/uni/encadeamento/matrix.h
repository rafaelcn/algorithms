#ifndef MATRIX_H
#define MATRIX_H

/**
 *
 * Assignment  done under the Data Structures class in UTFPR.
 *
 * authors: Rafael Campos Nunes
 *          Mikael Messias
 *
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
 * @brief
 * @param m
 * @param x
 * @param y
 * @param v
 */
int matrix_insert(Matrix *m, int x, int y, int v);

/**
 * @brief
 * @param m
 * @param x
 * @param y
 */
MatrixNode matrix_get_by_coordinate(Matrix *m, int x, int y);

/**
 * @brief
 * @param m
 * @param v
 */
MatrixNode matrix_get_by_value(Matrix *m, int v);

/**
 * @brief Prints the matrix structure
 * @param m A pointer to the Matrix to be printed.
 * @returns 1 on success and 0 if it didn't succeed.
 */
int matrix_print(Matrix m);

/**
 * @brief Print neighbours of an specific MatrixNode.
 * @param m The reference to be used when printing its neighbours.
 * @returns
 */
int matrix_print_neighbours(MatrixNode *m);

/**
 * @brief Frees the allocated Matrix.
 * @param m The matrix to be freed.
 */
void matrix_free(MatrixNode *m);


#endif // MATRIX_H
