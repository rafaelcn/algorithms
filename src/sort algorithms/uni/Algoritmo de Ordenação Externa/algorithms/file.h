/*
 *
 *                              UTFPR
 *
 * authors: Rafael Campos Nunes & Mikael Messias Pereira
 *
 * This file provides functions relative to files and a file structure itself
 * to be used on the external sort.
 */
#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct file {
    FILE *f;
    int pos;
    int MAX;
    int *buffer;
};

typedef struct file File;

/**
 * @brief Creates a random file with random elements.
 * @param name : The name of the file to be created and filled.
 * @param elements : The number of elements to fill the file.
 */
void file_create_random(char *, int);
/**
 * @brief Writes the numbers on the sorted buffer of the file to the file
 * itself.
 * @param file : The file structure used to read from the buffer and to write
 * it to another FILE structure inside it.
 * @param k :
 */
void file_save(char *, int[], int, int);

void file_save_number(char *, int, int);
/**
 * @param name: The name of the file
 * @param v : the data vector
 * @param n : size of the vector v
 * @param nl : write a new line? 1 for yes 0 for no.
 */
void file_fill(File *, int);

/**
 * @param name : The name of the file to be verified
 */
bool file_is_sorted(char *name);

#endif // FILE_H
