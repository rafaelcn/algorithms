#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>

#include "matrix.h"

struct node {
    int value;

    // Position of the node in the matrix
    uint32_t pos_x;
    uint32_t pos_y;

    struct node *top;
    struct node *bottom;
    struct node *left;
    struct node *right;
};

/**
 * @brief Checks if a given pointer is NULL.
 * @returns An integer representing whether the pointer is NULL or not, the
 * return possibilities are:
 * 1. The number 1 representing it is NULL
 * 2. The number 0 representing it isn't NULL
 */
static int check_pointer(void *p) {
    return p == NULL;
}

/**
 * @brief Prints a formatted error.
 * @param m The message to be printed.
 * @param line The line where the error was issued.
 */
static void pferror(char *m, int line) {
#ifdef __linux__
    fprintf(stderr, "\nError %s | matrix.c on line %d\n", m, line);
#elif
    fprintf(stderr, "\nError %s | matrix.c on line %d\n", m, line);
#endif // __linux__
}

Matrix *matrix_init(int x, int y) {
    Matrix *m = (Matrix*) malloc(sizeof(Matrix*));

    if (check_pointer(m)) {
        pferror("Couldn't initialise the Matrix, exiting.", __LINE__);
        exit(1);
    }

    // TODO: Create the Matrix if the allocation succeeds
    // The process of creating the Matrix is create a double linked list and
    // for each pair of lists concatenate (link) those sublist together.

    for (int i = 0; i < x; i++) {
        // Creating the HEAD node of the Matrix
        MatrixNode *HEAD = malloc(sizeof(MatrixNode));

        if (check_pointer(HEAD)) {
            pferror("Creating a MatrixNode failed, no memory?", __LINE__);
            exit(1);
        }

        HEAD->top = HEAD->bottom = NULL;
        HEAD->left = HEAD->right = NULL;

        // Setting its position on the Matrix
        HEAD->pos_x = i;
        // The HEAD element is always the first of its column
        HEAD->pos_y = 0;

        *m = HEAD;
        Matrix pointer = HEAD;

        for (int j = 1; j < y; j++) {

            MatrixNode *el = malloc(sizeof(MatrixNode));

            if (check_pointer(el)) {
                pferror("Creating a MatrixNode failed, no memory?", __LINE__);
                exit(1);
            }

            el->left = HEAD;
            el->right = NULL;
            el->bottom = el->top = NULL;
            el->pos_x = i;
            el->pos_y = j;

            HEAD->right = el;

        }



    }


    return m;
}
