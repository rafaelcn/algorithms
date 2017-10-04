typedef struct matrix *Matrix;

typedef struct matrix Node;

Matrix *init_matrix();

int insert_on_matrix(Matrix *m, int x, int y, int v); 

Node *search_by_coordinate(Matrix *m, int x, int y);

Node *search_by_value(Matrix *m);

int print_neighbors(Matrix *m);

void free_matrix(Matrix *m);