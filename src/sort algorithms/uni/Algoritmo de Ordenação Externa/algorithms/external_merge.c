#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "file.h"

#define M 100    // Internal memory size
#define R 1000   // Amount of keys to be sorted

int classify(char *);
void external_mergesort(char *);

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
    int memory[M];
    // the amount of files needed to sort the name file with M memory
    int files_read = 0;
    // the amount of keys read of a file
    int keys = 0;
    // temporary file name
    char tmp_file_name[20];

    FILE *f = fopen(name, "r");

    if (f == NULL) {
        fprintf(stderr, "Failed to open file %s.\n", name);
        exit(1);
    }

    do {
        fscanf(f, "%d", &memory[keys]);
        keys++;

        // If read numbers equals the size of the internal memory sort and
        // write them out to a temp file
        if(keys == M) {
            files_read++;
            sprintf(tmp_file_name, "data/temp%d.txt", files_read);
            heap(memory, M);
            file_save(tmp_file_name, memory, keys, 0);
            keys = 0;
        }
    } while (!feof(f));

    return files_read;
}

int procuraMenor(File* arq, int numArq, int K, int* menor) {
    int i;
    int idx = -1;

    //procura o menor valor na primeira posicao de cada buffer
    for (i = 0; i < numArq; i++) {
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

    //achou menor atualiza posi��o do buffer. Encher se estiver vazio (pos == MAX)
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

void intercala(char* nome, int numArq, int K) {
    //
    char novo[20];
    //
    int i;
    //
    int *buffer = (int*) malloc(K * sizeof(int));
    //
    File* arq = (File*) malloc(numArq * sizeof(File));

    for (i = 0; i < numArq; i++) {
        sprintf(novo, "data/temp%d.txt", i+1);
        arq[i].f = fopen(novo, "r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int*) malloc(K * sizeof(int));
        file_fill(&arq[i], K);
    }

    //enquanto houver arquivos para processar
    int menor;
    int quantBuffer = 0;

    while (procuraMenor(arq, numArq, K, &menor) == 1) {
        buffer[quantBuffer] = menor;
        quantBuffer++;
        if(quantBuffer == K){
            file_save(nome, buffer, K, 1);
            quantBuffer = 0;
        }
    }

    //salva dados ainda no buffer
    if (quantBuffer != 0) {
        file_save(nome, buffer, quantBuffer, 1);
    }

    for (i = 0; i < numArq; i++) {
        free(arq[i].buffer);
    }

    free(arq);
    free(buffer);
}

void external_mergesort(char *name) {
    //chama a funcao criaArqOrd que realiza a classificacao dos arquivos
    //a funcao retorna o número de arquivos gerados.
    int numArqs = classify(name);

    //calcula o tamanho de cada buffer?
    int K = M / (numArqs + 1); //+1 buffer de entrada

    printf("M = %d, numArqs = %d, k = %d\n", M, numArqs, K);

    //cria arquivo de saida
    FILE *fs = fopen("data/sorted.txt", "w");
    fclose(fs);

    //intercala os arquivos ordenados e salva em saida.txt
    intercala("data/sorted.txt", numArqs, M);
}
