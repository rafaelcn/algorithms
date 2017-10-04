#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct matrix {
	int v;
	struct matrix *top;
	struct matrix *bottom;
	struct matrix *left;
	struct matrix *right;
}

Matrix *init_matrix(int x, int y){
	//Matrix *m = (Matrix*) malloc(sizeof(Matrix));
}
