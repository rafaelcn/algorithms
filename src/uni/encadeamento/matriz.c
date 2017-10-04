#include <stdio.h>
#include <stdlib.h>

struct matrix {
	int v;
	struct matrix *top;
	struct matrix *bottom;
	struct matrix *left;
	struct matrix *right;
}
