#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <limits.h>

#include "heap.h"

int main(void) {

    // TODO: Make it easier to create this heap data structure.

    Heap *h = malloc(sizeof(Heap));

    // allocate a heap of 50 elements
    h->vector = calloc(1, sizeof(HeapElement[50]));

    for (int i = 0; i < 50; i++) {
        h->vector[i].key = INT_MAX;
    }

    h->index = 0;
    h->size = 0;

    sift_up(h, 2, 0);
    sift_up(h, 3, 3);
    sift_up(h, 5, 0);
    sift_up(h, 3, 2);
    sift_up(h, 6, 1);
    sift_up(h, 4, 0);
    sift_up(h, 1, 0);
    sift_up(h, 7, 1);

    heap(h);

    for (uint16_t i = 0; i < h->size; i++) {
        fprintf(stdout, "{.key=%d weight=%d}\n", h->vector[i].key,
                h->vector[i].weight);
    }

    HeapElement a = sift_down(h, 123, 12);

    fprintf(stdout, "Removed: {.key=%d weight=%d}\n", a.key, a.weight);

    for (uint16_t i = 0; i < h->size; i++) {
        fprintf(stdout, "{.key=%d weight=%d}\n", h->vector[i].key,
                h->vector[i].weight);
    }

    free(h->vector);
    free(h);

    return 0;
}
