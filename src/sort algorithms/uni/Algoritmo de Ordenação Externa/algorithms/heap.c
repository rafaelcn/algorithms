#include "heap.h"

#include <stdlib.h>

void heap(Heap *);

void swap(HeapElement *a, HeapElement *b) {
    HeapElement tmp = *a;
    *a = *b;
    *b = tmp;
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

void sift_up(Heap *heap_t, int key, int weight) {

    if (heap_t == NULL) {
        return;
    }

    HeapElement he;

    he.key = key;
    he.weight = weight;

    heap_t->vector[heap_t->index] = he;

    heap_t->index = heap_t->index+1;
    heap_t->size = heap_t->index;

    // I know it's time consuming but I'm going with the faster way to
    // code... (frown).

    heap(heap_t);
}

HeapElement sift_down(Heap* heap_t, int key, int weight) {
    // This function is not entirely correct because it does more than what's
    // intended to be done with her. It removes the first element of the heap
    // and then inserts another on the same place and calls heapify after that.

    HeapElement e = heap_t->vector[0];

    heap_t->vector[0].key = key;
    heap_t->vector[0].weight = weight;

    // Again this is time consuming but I'm low on time to do this in a better
    // way. It must work.

    heap(heap_t);

    return e;
}

void heap(Heap *h) {

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
