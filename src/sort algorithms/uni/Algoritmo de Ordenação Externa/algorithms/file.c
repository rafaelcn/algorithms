#include "file.h"

#include <math.h>

void file_create_random(char *name, int elements) {

    int i;
    FILE *f = fopen(name, "w");

    int *dummy;

    srand((unsigned int)&dummy);

    for(i = 0; i < elements; i++){
        fprintf(f, "%d\n", rand());
    }

    fclose(f);
}

void file_fill(File* file, int K) {

    int i;

    if (file->f == NULL) {
        return;
    }

    file->pos = 0;
    file->MAX = 0;

    for (i = 0; i < K; i++) {
        if (!feof(file->f)) {
            fscanf(file->f, "%d", &file->buffer[file->MAX]);
            file->MAX++;
        } else {
            fclose(file->f);
            file->f = NULL;
            break;
        }
    }
}


void file_save(char *name, int *v, int n, int nl) {

    int i;
    FILE *f = fopen(name, "a");

    for (i = 0; i < n-1; i++) {
        fprintf(f, "%d\n", v[i]);
    }

    if (nl == 0) {
        fprintf(f, "%d", v[n-1]);
    } else {
        fprintf(f, "%d\n", v[n-1]);
    }

    fclose(f);
}

void file_save_number(char *name, int key, int nl) {

    FILE *f = fopen(name, "a");

    if (nl == 0) {
        fprintf(f, "%d", key);
    } else {
        fprintf(f, "%d\n", key);
    }

    fclose(f);
}

bool file_is_sorted(char *name) {

    FILE* f = fopen(name, "r");

    if (!f) {
        fprintf(stderr, "The file %s could not be found.\n", name);
        return false;
    }

    int read1 = 0;
    int read2 = 0;
    int lines = 0;

    do {
        int va, vb;

        read1 = fscanf(f, "%d", &va);
        read2 = fscanf(f, "%d", &vb);

        lines += 2;

        if (va > vb) {
            printf("\n%d > %d on line %d\n", va, vb, lines);
            return false;
        }
    } while (read1 == 1 && read2 == 1);

    return true;
}
