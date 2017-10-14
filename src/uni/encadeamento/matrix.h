/**
 *
 *
 * authors: Rafael Campos Nunes
 *          Mikael Messias
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
 * @brief Print neighbours of an specific MatrixNode.
 * @param m The reference to be used when printing its neighbours.
 */
int matrix_print_neighbours(Matrix *m);

/**
 * @brief Frees the allocated Matrix.
 * @param m The matrix to be freed.
 */
void matrix_free(Matrix *m);
