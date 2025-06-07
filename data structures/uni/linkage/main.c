#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Would be best to filter by compiler and not by platform as it isn't assured
// that the define is implemented in the respective compiler.
#ifdef __windows__
#include <locale.h>
#endif // __windows__

#include "matrix.h"
#include "macros.h"
#include "assertions.h"

// Prints usage about the program.
void usage();
// Prints an interactive Menu where you can mess with everything.
void interactive();
// Does a testing of the matrix functions suite.
int test(int argc, char **argv);
// Test if a matrix is pointer is null or not.
int check_matrix(Matrix *m);


int main(int argc, char **argv) {
#ifdef __windows__
    // Little fix for windows shitty console (I'm looking at you CMD.exe).
    set_locale(LC_ALL, "");
#endif // __windows__


    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0) {
            usage();
            return 0;
        } else if (strcmp(argv[1], "--interactive") == 0) {
            interactive();
        } else if (strcmp(argv[1], "--test") == 0) {
            test(argc, argv);
        }
    } else {
        usage();
    };

    return 0;
}

void usage() {
    printf("\nUsage: ./matrix --<flag>");
    printf("\n\nFlags available:");
    printf("\n\t--help");
    printf("\n\t--interactive");
    printf("\n\t--test <x> <y>");
    printf("\n\nWhere: ");
    printf("\n\tx - Rows of the matrix");
    printf("\n\ty - Columns of the matrix\n");
}

int test(int argc, char **argv) {

    int dim[2] = {3, 3};

    if (argc > 3) {
        dim[0] = atoi(argv[2]);
        dim[1] = atoi(argv[3]);
    }

    Matrix *m = matrix_init(dim[0], dim[1]);

    printf("\n\nTesting matrix_print\n\n");

    matrix_print(*m);

    printf("\n\nTesting matrix_print_element | matrix_get_by_coordinate\n\n");

    matrix_print_element(matrix_get_by_coordinate(*m, 1, 2));
    matrix_print_element(matrix_get_by_coordinate(*m, 2, 2));
    matrix_print_element(matrix_get_by_coordinate(*m, 3, 2));

    printf("\n\nTesting matrix_print_neighbours\n\n");

    matrix_print_neighbours(matrix_get_by_coordinate(*m, 0, 1));
    matrix_print_neighbours(matrix_get_by_coordinate(*m, 0, 0));
    matrix_print_neighbours(matrix_get_by_coordinate(*m, 1, 1));
    matrix_print_neighbours(matrix_get_by_coordinate(*m, 2, 1));
    matrix_print_neighbours(matrix_get_by_coordinate(*m, 1, 2));

    printf("\n\nTesting: matrix_get_by_value");

    matrix_print_element(matrix_get_by_value(*m, 1));
    matrix_print_element(matrix_get_by_value(*m, 2));
    matrix_print_element(matrix_get_by_value(*m, 3));

    printf("\n\nTesting: matrix_get_value\n");

    ASSERT(*(matrix_get_value(matrix_get_by_coordinate(*m, 1, 2))), 3,
           "Testing if the value of the MatrixNode(1,2) == 3");

    ASSERT(*(matrix_get_value(matrix_get_by_coordinate(*m, 1, 3))), 4,
           "Testing if the value of the MatrixNode(1,2) == 4");

    ASSERT(*(matrix_get_value(matrix_get_by_coordinate(*m, 2, 2))), 4,
           "Testing if the value of the MatrixNode(1,2) == 4");

    matrix_free(*m);

    return 0;
}

void interactive() {
    // The chosen option in the menu
    int op = 0;

    Matrix* m;
    // Coordinates of the Matrix
    int x, y;
    int v;

    while (op != 10){
        printf("\n1 -> Create a Matrix\n");
        printf("2 -> Create a MatrixNode\n");
        printf("3 -> Get a MatrixNode by coordinate\n");
        printf("4 -> Get a MatrixNode by value\n");
        printf("5 -> Print the Matrix\n");
        printf("6 -> Print the Matrix HEADS\n");
        printf("7 -> Print the neighbours of a given MatrixNode\n");
        printf("8 -> Remove a MatrixNode by coordinate\n");
        printf("9 -> Remove a MatrixNode by value\n");
        printf("10 -> Exit\n");
        printf(": ");

        scanf("%d", &op);

        switch (op) {
        case 1: {
            printf("Rows: ");
            scanf("%d", &x);
            printf("Columns: ");
            scanf("%d", &y);

            m = matrix_init(x, y);
            break;
        }
        case 2:
            if (check_matrix(m)) {
                printf("\nEnter the position where the value should be \
inserted: ");
                scanf("%d %d", &x, &y);
                printf("\nEnter the value to be inserted: \n");
                scanf("%d", &v);
                matrix_insert(m,x,y,v);
            }
            break;
        case 3:
            if (check_matrix(m)) {
                printf("\nEnter the position of the MatrixNode: ");
                scanf("%d %d", &x, &y);
                matrix_print_element(matrix_get_by_coordinate(*m, x, y));
            }
            break;
        case 4: {
            if (check_matrix(m)) {
                int v = 0;

                printf("\nEnter the value of the MatrixNode: ");
                scanf("%d", &v);

                matrix_print_element(matrix_get_by_value(*m, v));
            }
            break;
        }
        case 5:
            if (check_matrix(m)) {
                matrix_print(*m);
            }
            break;
        case 6:
            if (check_matrix(m)) {
                matrix_print_heads(*m);
            }
            break;
        case 7:
            if (check_matrix(m)) {
                printf("Enter the position of the MatrixNode: ");
                scanf("%d %d", &x, &y);

                matrix_print_neighbours(matrix_get_by_coordinate(*m, x, y));
            }
            break;
        case 8:
            if (check_matrix(m)) {
                printf("\nEnter the position of the MatrixNode to be removed:\
 ");
                scanf("%d %d", &x, &y);
                matrix_remove_by_coordinate(m,x,y);
            }
            break;
        case 9:
            if (check_matrix(m)) {
                printf("\nEnter the value of the MatrixNode to be removed: ");
                scanf("%d", &v);
                matrix_remove_by_value(m,v);
            }
            break;
        case 10:
            break;
        default:
            printf("Invalid option. Enter a valid one [1-10]\n");
        }
    }

    if (m != NULL) {
        matrix_free(*m);
    }
}

int check_matrix(Matrix *m) {
    if (m != NULL) {
        return 1;
    } else {
        printf("\nCreate a Matrix first.\n");
        return 0;
    }
}