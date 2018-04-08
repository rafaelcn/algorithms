#include <stdio.h>
#include <stdlib.h>

#include <inttypes.h>

#include "macros.h"
#include "matrix.h"


struct node {
    int value;

    // Position of the node in the matrix
    uint32_t pos_x;
    uint32_t pos_y;

    MatrixNode *top;
    MatrixNode *bottom;
    MatrixNode *left;
    MatrixNode *right;
};


static uint32_t rows;
static uint32_t columns;

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
static void pferror(const char *m, const int line) {
#ifdef __linux__
    fprintf(stderr, "%sError: %s | matrix.c on line %d%s\n", ANSI_COLOR_RED,
            m, line, ANSI_COLOR_RESET);
#elif
    fprintf(stderr, "\nError: %s | matrix.c on line %d\n", m, line);
#endif // __linux__
}

/**
 * @brief Prints a formatted info.
 * @param m The message to be printed.
 */
static void pfinfo(const char *m) {
#ifdef __linux__
    fprintf(stderr, "\n%sInfo: %s%s", ANSI_COLOR_GREEN, m, ANSI_COLOR_RESET);
#elif
    fprintf(stderr, "\nInfo: %s", m);
#endif // __linux__
}

Matrix *matrix_init(int x, int y) {
    Matrix *m = (Matrix*) malloc(sizeof(Matrix*));

    if (check_pointer(m)) {
        pferror("Couldn't initialise the Matrix, exiting.", __LINE__);
        exit(1);
    }

    // Set to be used in other functions
    rows = x;
    columns = y;

    // The process of creating the Matrix is create all the lines of the list
    // first and then create a double linked list and for each pair of lists
    // concatenate (link) those sublist together.

    // Walks along the HEADs.
    MatrixNode* walker = NULL;

    // Create every HEAD of the Matrix
    for (int i = 0; i < x; i++) {
        // Creating the HEAD node of the Matrix
        MatrixNode *HEAD = malloc(sizeof(MatrixNode));

        if (check_pointer(HEAD)) {
            pferror("Creating a MatrixNode failed, no memory?", __LINE__);
            exit(1);
        }

        // Setting its position on the Matrix
        HEAD->pos_x = i;
        // The HEAD element is always the first of its column
        HEAD->pos_y = 0;

        // Only for testing purposes
        HEAD->value = i;

        if (*m == NULL) {
            // Empty Matrix
            HEAD->top = HEAD->bottom = NULL;
            *m = HEAD;
        } else {
            walker->bottom = HEAD;
            HEAD->top = walker;
        }

        HEAD->left = HEAD->right = NULL;

        walker = HEAD;

#ifdef DEBUG
        const char *message = "Creating HEAD %d. Walker %p |\
Walker's top is %p";
        int size = snprintf(NULL, 0, message, i, walker, walker->top);
        char buffer[size+1];
        snprintf(buffer, size, message, i, walker, walker->top);
        pfinfo(buffer);
#endif // DEBUG
    }

    // Creating every line for each HEAD.
    for (int i = 0; i < x; i++) {
        MatrixNode* HEAD = NULL;
        if (i == 0) {
            // Points to the first position of the Matrix available

            // FIXME: This looks like Macgyver, need to revisit this later.
            while (walker->top != NULL) {
                walker = walker->top;
            }

            HEAD = walker;
        } else {
            HEAD = walker->bottom;
            walker = walker->bottom;

            HEAD = walker;
        }

        for (int j = 1; j < y; j++) {
            MatrixNode *e = malloc(sizeof(MatrixNode));

            if (check_pointer(e)) {
                pferror("Creating a MatrixNode failed, no memory?", __LINE__);
                exit(1);
            }

            HEAD->right = e;

            e->left = HEAD;
            e->bottom = e->top = NULL;
            // not sure if the below will work well
            e->pos_x = i;
            e->pos_y = j;
            e->value = i+j;


#ifdef DEBUG
            const char *message = "Creating element %d. Row walker %p |\
Row walker's left is %p";
            int size = snprintf(NULL, 0, message, j, HEAD, HEAD->left);
            char buffer[size+1];
            snprintf(buffer, size, message, j, HEAD, HEAD->left);
            pfinfo(buffer);
#endif // DEBUG

            HEAD = e;
        }
    }

    MatrixNode *row_walker = *m;

    // Concatenation of every row of the Matrix
    for (int i = 0; i < x; i++) {
        MatrixNode *row = row_walker;
        MatrixNode *row_next = row_walker->bottom;

        if (row_next == NULL) {
            break;
        }

        // Move one column right
        row = row->right;
        row_next = row_next->right;

        for (int j = 0; j < y; j++) {
            row->bottom = row_next;
            row_next->top = row;

            // It only needs one verification
            if (row->right != NULL) {
                row = row->right;
                row_next = row_next->right;
            }
        }

        row_walker = row_walker->bottom;
    }


    return m;
}

int matrix_insert(Matrix *m, uint32_t x, uint32_t y, int v) {
    if (check_pointer(m)) {
        pferror("Argument given to matrix_insert is null",
                __LINE__);
        return 0;
    } else if (x >= rows || y >= columns) {
        pferror("Values given are out of bounds", __LINE__);
        return 0;
    }

    MatrixNode *walker = *m;

    while(walker->pos_x != x && walker->bottom != NULL){
        walker = walker->bottom;
    }

    while(walker->pos_y != y && walker->right != NULL){
        walker = walker->right;
    }

    walker->value = v;
    return 1;
}

int matrix_remove_by_coordinate(Matrix* m, uint32_t x, uint32_t y) {
    if (check_pointer(m)) {
        pferror("Argument given to matrix_remove_by_coordinate is null",
                __LINE__);
        return 0;
    } else if (x >= rows || y >= columns) {
        pferror("Values given are out of bounds", __LINE__);
        return 0;
    }

    MatrixNode *HEAD = *m;

    // Walks through the head of all rows until it finds the position y.
    while(HEAD->bottom != NULL && HEAD->pos_x != x) {
        HEAD = HEAD->bottom;
    }

    MatrixNode *walker = HEAD;

    // Walks through the columns in position x until it finds the position y.
    while(walker->right != NULL && walker->pos_y != y) {
        walker = walker->right;
    }

    if (walker->pos_x != x && walker->pos_y != y) {
        pferror("Unable to find this coordinate", __LINE__);
        return 0;
    }
    else {
        // It does not look right, but I wasn't able to do the removal without those auxiliary pointers.
        MatrixNode *next = walker, *tmp = next->left;

        // Walks through the row until it finds the last element.
        while(next->right != NULL) {
            next = next->right;
        }

        uint32_t i = walker->pos_y + 1;

        // Rearranges the pointers of nodes close to the one to be removed: 
        // the last of the row.
        if(walker->right == NULL) {
            if(walker->top != NULL) {
                if(walker->bottom != NULL) {
                    walker->top->bottom = walker->bottom;
                    walker->bottom->top = walker->top;
                }
                else {
                    walker->top->bottom = NULL;
                    if(walker->top != NULL) {
                        walker->top->bottom = NULL;
                    }
                }
            }
            if(walker->left != NULL) {
                walker->left->right = NULL;
            }

            // Jumps the while loop below, since there's nothing else to do.
            i = columns;
        }


        // If the first node will be removed, the Matrix pointer also needs
        // to be rearranged.
        if(*m == walker) {
            if((*m)->right != NULL) {
                // The first element will be the one in the next column, 
                // if there are any.
                *m = (*m)->right;
            }
            else {
                // The first element will be the next head, if there are any.
                *m = (*m)->bottom;
            }
        }

        // Rearranges the pointers of nodes close to the one to be removed.
        // It works like this: starting from the last column of row x, 
        // move the pointer next to the left position until the pointer is null.
        // until the pointer next not null.
        while(i < columns && next != NULL) {
            tmp = next->left;

            next->top = tmp->top;
            next->bottom = tmp->bottom;

            if(tmp->top != NULL) {
                tmp->top->bottom = next;
            }
            if(tmp->bottom != NULL) {
                tmp->bottom->top = next;
            }
            if(tmp == walker) {
                next->left = tmp->left;

                if(tmp->left != NULL) {
                    tmp->left->right = next;
                }
            }

            next->pos_y--;

            next = next->left;

            i++;
        }

        free(walker);
    }

    return 1;
}

int matrix_remove_by_value(Matrix *m, int v) {
    if (check_pointer(m)) {
        pferror("Argument given to matrix_remove_by_value is null", __LINE__);
        return 0;
    }

    MatrixNode *HEAD = *m, *walker = *m;

    while (HEAD->bottom != NULL) {
        walker = HEAD;
        while (walker->right != NULL) {
            if (walker->value == v){
                if (walker->top != NULL) {
                    walker->top->bottom = walker->bottom;
                }
                if (walker->bottom != NULL) {
                    walker->bottom->top = walker->top;
                }
                if (walker->left != NULL) {
                    walker->left->right = walker->right;
                }
                if (walker->right != NULL) {
                    walker->right->left = walker->left;
                }
                free(walker);
            }
            walker = walker->right;
        }
        HEAD = HEAD->bottom;
    }

    return 1;
}

MatrixNode *matrix_get_by_coordinate(MatrixNode *m, uint32_t x, uint32_t y) {
    if (check_pointer(m)) {
        pferror("Argument given to matrix_get_by_coordinate is null",
                __LINE__);
        return NULL;
    } else if (x >= rows || y >= columns) {
        pferror("Values given are out of bounds", __LINE__);
        return NULL;
    }

    MatrixNode *desired = m;

    while (desired->pos_x != x) {
        desired = desired->bottom;
    }

    while (desired->pos_y != y) {
        desired = desired->right;
    }

    return desired;
}

MatrixNode *matrix_get_by_value(MatrixNode *m, int v) {
    if (check_pointer(m)) {
        pferror("Argument given to matrix_get_by_value is null", __LINE__);
        return NULL;
    }

    MatrixNode *desired = NULL;

    while (m->bottom != NULL) {
        while (m->right != NULL) {
            if (m->value == v) {
                desired = m;
                // While some might say that a goto is not a ideal solution
                // but it is, and here's why:
                // Otherwise to break a nested loop I'd have to use flags,
                // they would cost a little bit of memory which I wouldn't
                // like to spare. Further on unconditional jmps are
                // everywhere in machine code, I'm just exploring it on this
                // level.
                goto end;
            }
            m = m->right;
        }

        m = m->bottom;
    }

end:
    return desired;
}

int *matrix_get_value(MatrixNode *m) {
    if (check_pointer(m)) {
        pferror("MatrixNode given is null", __LINE__);
        return NULL;
    }

    return &(m->value);
}

int matrix_print(Matrix m) {
    if (check_pointer(m)) {
        pferror("Argument given to matrix_print is null", __LINE__);
        return 0;
    }

    MatrixNode *HEAD = m;

    newline;

    while (HEAD != NULL) {
        m = HEAD;

        while (m != NULL) {
            printf(" -- [%d (%d,%d)]", m->value, m->pos_x, m->pos_y);

            // Rightmost column of the matrix.
            if (m->right == NULL) {
                printf(" --");
            }

            m = m->right;
        }
        newline;

        HEAD = HEAD->bottom;
    }

    return 1;
}

void matrix_print_heads(MatrixNode *m) {
    if (check_pointer(m)) {
        pferror("Argument given to matrix_print_heads is null", __LINE__);
        return;
    }

    printf("\n\t--(%d)--\n\t%4s", m->value, "|");
    matrix_print_heads(m->bottom);
}

int matrix_print_element(MatrixNode *m) {
    if (check_pointer(m)) {
        pferror("Argument given to matrix_print_element is null", __LINE__);
        return 0;
    }

    printf("\n[%d (%d,%d)]", m->value, m->pos_x, m->pos_y);

    return 1;
}

int matrix_print_neighbours(MatrixNode *m) {
    if (check_pointer(m)) {
        pferror("Argument given to matrix_print_neighbours is null",
                __LINE__);
        return 0;
    }


    // Should minimise this code using some sort of generalization
    if (!check_pointer(m->top)) {
        printf("\t\t  [%d (%d,%d)]\n", (m->top)->value, (m->top)->pos_x,
               (m->top)->pos_y);
    }  else {
        printf("\t\t    %sNULL%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    }


    if (!check_pointer(m->left)) {
        printf("\t[%d (%d,%d)] ", (m->left)->value, (m->left)->pos_x,
               (m->left)->pos_y);
    } else {
        printf("\t     %sNULL%s ", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    }

    printf("%s[%d (%d,%d)]%s", ANSI_COLOR_GREEN, m->value, m->pos_x,
           m->pos_y, ANSI_COLOR_RESET);

    if (!check_pointer(m->right)) {
        printf(" [%d (%d,%d)]", (m->right)->value, (m->right)->pos_x,
               (m->right)->pos_y);
    } else {
        printf(" %sNULL%s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    }


    if (!check_pointer(m->bottom)) {
        printf("\n\t\t  [%d (%d,%d)]", (m->bottom)->value,
               (m->bottom)->pos_x, (m->bottom)->pos_y);
    }  else {
        printf("\n\t\t    %sNULL%s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    }

    newline;
    newline;

    return 1;
}

void matrix_free(MatrixNode *m) {
    //The free method is described in the Free section of the paper.
    MatrixNode *walker = m;


    while(walker != NULL) {
        m = walker;

        while (m != NULL) {
            MatrixNode *e = m;
            m = m->right;

            free(e);
        }

        walker = walker->bottom;
    }

    free(m);
}
