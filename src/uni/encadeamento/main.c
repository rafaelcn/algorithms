#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Would be best to filter by compiler and not by platform as it isn't assured
// that the define is implemented in the respective compiler.
#ifdef __windows__
#include <locale.h>
#endif // __windows__

#include "matrix.h"

// Prints usage about the program
void usage();

int main(int argc, char **argv) {
#ifdef __windows__
    // Little fix for windows shitty console (I'm looking at you CMD.exe).
    set_locale(LC_ALL, "");
#endif // __windows__

    int x = 3;
    int y = 3;

// TODO: Interpret input and make a menu to interact with the matrix
    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0) {
            usage();
            return 0;
        }

        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }

    Matrix *m = matrix_init(x, y);

    matrix_print(*m);

    matrix_free(*m);

    return 0;
}

void usage() {
    printf("\nUsage: ./matrix <x> <y>");
    printf("\n\nWhere: ");
    printf("\nx - Rows of the matrix");
    printf("\ny - Columns of the matrix");
}
