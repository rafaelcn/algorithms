#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "file.h"

#define M 100    // Internal memory size
#define R 1000   // Amount of keys to be sorted

int classify(char *);
void merge(char *, int, int);
void external_mergesort(char *);

int search_lower(File *, int, int, int *);

int main(void) {

    file_create_random("data/data.txt", R);
    external_mergesort("data/data.txt");

    if (file_is_sorted("data/sorted.txt")) {
        printf("It is sorted!\n");
    } else {
        printf("It isn't sorted.\n");
    }

    return 0;
}

int classify(char *name) {
    // the amount of files needed to sort the name file with M memory
    int files_read = 0;
    // the amount of keys read of a file (prob. won't need it)
    int keys = 0;
    // temporary file name
    char tmp_file_name[20];
    // The weight
    int weight = 0;

    FILE *f = fopen(name, "r");

    // Initializing the Heap
    Heap *h = malloc(sizeof(Heap));
    h->vector = calloc(M, sizeof(HeapElement));

    if (f == NULL) {
        fprintf(stderr, "Failed to open file %s.\n", name);
        exit(1);
    }

    do {
        int number;

        if (keys == M) {
            keys--;

            fscanf(f, "%d", &number);

            HeapElement he = sift_down(h);

            if (number < he.key) {
                weight++;
            }

            sift_up_i(h, number, weight, 0);

            sprintf(tmp_file_name, "data/temp%d.txt", files_read);
            file_save_number(tmp_file_name, he.key, 0);

            files_read++;
        } else {
            fscanf(f, "%d", &number);
            keys++;

            // Inserting the number in the heap while it isn't full
            sift_up(h, number, weight);
        }
    } while (!feof(f));

    // Verify if the cause of the exit loop wasn't because of an error
    if (ferror(f)) {
        fprintf(stderr, "I/O error while at classify.\n");
        // Interrupt the execution of the program
        exit(1);
    }

    return files_read;
}


int search_lower(File* arq, int files_num, int K, int* menor) {

    int i = 0;
    int idx = -1;

    // Searches for the lower number on the first position of each file
    for (i = 0; i < files_num; i++) {
        if (arq[i].pos < arq[i].MAX) {
            if (idx == -1) {
                idx = i;
            } else {
                if (arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
                {
                    idx = i;
                }
            }
        }
    }

    //achou menor atualiza posi��o do buffer. Encher se estiver vazio
    // (pos == MAX)
    if (idx != -1) {
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if (arq[idx].pos == arq[idx].MAX) {
            file_fill(&arq[idx], K);
        }
        return 1;
    } else {
        return 0;
    }
}


void merge(char* name, int files, int K) {
    //
    char tmp_file_name[20];
    //
    int i;
    //
    File* file = (File*) malloc(files * sizeof(File));

    for (i = 0; i < files; i++) {
        sprintf(tmp_file_name, "data/temp%d.txt", i+1);
        file[i].f = fopen(tmp_file_name, "r");
        file[i].MAX = 0;
        file[i].pos = 0;
        file[i].buffer = (int*) malloc(K * sizeof(int));
        file_fill(&file[i], K);
    }

    // While there are files to process
    int smaller;
    int status;
    int heapSize = 0;
    int weight = 0;

    Heap *h = malloc(sizeof(Heap));
    h->vector = calloc(M, sizeof(HeapElement));

    do {
        status = search_lower(file, files, K, &smaller);

        if(heapSize == K){
            heapSize--;

            if(status == 1) {
                HeapElement he = sift_down(h);

                if(smaller < he.key) {
                    weight++;
                }

                sift_up_i(h, smaller, weight, 0);

                file_save_number(name, he.key, 0);
            }
        }
        else {
            // If there are data to be written
            if(status == 1) {
                sift_up(h, smaller, weight);
                heapSize++;
            }
        }
    } while(status == 1);

    // Save the data of the heap
    while (heapSize != 0) {
        HeapElement he = sift_down(h);
        int nl = 0;
        if(heapSize == 1) {
            nl = 1;
        }
        file_save_number(name, he.key, nl);
        heapSize--;
    }

    for (i = 0; i < files; i++) {
        free(file[i].buffer);
    }

    free(file);
}

void external_mergesort(char *name) {
    // Calls the classify function that returns the number of files created
    // on that step.
    int num_files = classify(name);

    //calcula o tamanho de cada buffer?
    int K = M / (num_files + 1); //+1 buffer de entrada

    printf("M = %d, num_files = %d, k = %d\n", M, num_files, K);

    // creates the final file that stores the sorted numbers
    FILE *fs = fopen("data/sorted.txt", "w");

    if (fs == NULL) {
        fprintf(stderr, "Sorted file couldn't be created. Halting...\n");
        // as the function doesn't return anything we call exit directly
        exit(-1);
    }

    fclose(fs);

    // Merges the files generated in the classify step.
    merge("data/sorted.txt", num_files, M);
}
