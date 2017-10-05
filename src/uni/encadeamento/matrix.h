typedef struct matrix Matrix;

Matrix **matrix_init(int x, int y);

int matrix_insert(Matrix **m, int x, int y, int v); 

Matrix *matrix_get_by_coordinate(Matrix **m, int x, int y);

Matrix *matrix_get_by_value(Matrix **m, int v);

int matrix_print_neighbors(Matrix **m);

void matrix_free(Matrix **m);