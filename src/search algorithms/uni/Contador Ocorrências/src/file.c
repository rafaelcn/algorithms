#include "file.h"

char *file_load(char *filename) {

    FILE* fs = fopen(filename, "r");

    if (fs == NULL) {
        fprintf(stderr, "File %s couldn't be read\n\n", filename);
        exit(EXIT_FAILURE);
    }

    char *words = calloc(MAX_CHARS, sizeof(char));

    do {
        fread(words, sizeof(char), MAX_CHARS, fs);
    } while (!feof(fs));

#ifdef DEBUG
    fprintf(stdout, "\n\nWords read: %s\n\n", words);
#endif

    return words;
}
