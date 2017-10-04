struct matrix **matrix_init();

int matrix_insert(struct matrix **, int x, int y, int v); 

struct matrix *matrix_get_by_coordinate(struct matrix **, int x, int y);

struct matrix *matrix_get_by_value(struct matrix **, int v);

int matrix_print_neighbors(struct matrix **);

void matrix_free(struct matrix **);