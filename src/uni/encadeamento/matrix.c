#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct matrix{
	int value;
	struct matrix *top;
	struct matrix *bottom;
	struct matrix *left;
	struct matrix *right;
}