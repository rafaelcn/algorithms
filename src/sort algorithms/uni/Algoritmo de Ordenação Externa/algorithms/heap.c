#include "heap.h"

#include <stdlib.h>

void heap(Heap *);

void swap(HeapElement *a, HeapElement *b) {
    HeapElement tmp = *a;
    *a = *b;
    *b = tmp;
}

Heap *heap_make(int size) {

    Heap *h = malloc(sizeof(Heap));

    if (h == NULL) {
        exit(1);
    }

    h->vector = calloc(size, sizeof(HeapElement));

    return h;
}

void heapify(HeapElement *heap_elements, int n, int i) {

    int smallest = i;

    int l = 2*i+1;
    int r = 2*i+2;

    int smallest_weight = heap_elements[smallest].weight;

    if (l < n) {
        int l_weight = heap_elements[l].weight;

        if (smallest_weight < l_weight) {
            smallest = l;
        } else if (smallest_weight == l_weight) {
            if (heap_elements[smallest].key < heap_elements[l].key) {
                smallest = l;
            }
        }
    }

    if (r < n) {
        int r_weight = heap_elements[r].weight;

        if (smallest_weight < r_weight) {
            smallest = r;
        } else if (smallest_weight == r_weight) {
            if (heap_elements[smallest].key < heap_elements[r].key) {
                smallest = r;
            }
        }
    }

    if (i != smallest) {
        swap(&heap_elements[i], &heap_elements[smallest]);
        heapify(heap_elements, n, smallest);
    }
}

void sift_up_i(Heap *heap_t, int key, int weight, int index) {

    if (heap_t == NULL) {
        return;
    }

    HeapElement he;

    he.key = key;
    he.weight = weight;

    heap_t->vector[index] = he;

    // I know it's time consuming but I'm going with the faster way to
    // code... (frown).

    heap_sort(heap_t);
}

void sift_up(Heap *heap_t, int key, int weight) {

    if (heap_t == NULL) {
        return;
    }

    sift_up_i(heap_t, key, weight, heap_t->index);

    heap_t->index = heap_t->index+1;
    heap_t->size = heap_t->index;
}

HeapElement sift_down(Heap* heap_t) {

    HeapElement e = heap_t->vector[0];

    // Again this is time consuming but I'm low on time to do this in a better
    // way. It must work.

    heap_sort(heap_t);

    return e;
}

void heap_sort(Heap *h) {

    if (h == NULL) {
        return;
    }

    for (int i = h->size/2-1; i >= 0; i--) {
        heapify(h->vector, h->size, i);
    }

    for (int i = h->size-1; i >=0; i--) {
        swap(h->vector, h->vector+i);
        heapify(h->vector, i, 0);
    }
}
