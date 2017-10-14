#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Would be best to filter by compiler and not by platform as it isn't assured
// that the define is implemented in the respective compiler.
#ifdef __windows__
    #include <locale.h>
#endif // __windows__

int main(int argc, char **argv) {
#ifdef __windows__
    // Little fix for windows shitty console (I'm looking at you CMD.exe).
    set_locale(LC_ALL, "");
#endif

    // TODO: Interpret input and make a menu to interact with the matrix


    Matrix *m = matrix_init(5, 3);

    matrix_print(*m);

    return 0;
}
