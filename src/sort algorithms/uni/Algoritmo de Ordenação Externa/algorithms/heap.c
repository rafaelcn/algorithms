#include "heap.h"

struct heap_element {
    int key;
    int weight;
};

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int *v, int n, int i) {

    int smallest = i;

    int l = 2*i+1;
    int r = 2*i+2;

    if (v[smallest] < v[l] && l < n) {
        smallest = l;
    }

    if (v[smallest] < v[r] && r < n) {
        smallest = r;
    }

    if (i != smallest) {
        swap(&v[i], &v[smallest]);
        heapify(v, n, smallest);
    }
}

void heap(int *v, int n) {

    for (int i = n/2-1; i >= 0; i--) {
        heapify(v, n, i);
    }

    for (int i = n-1; i >=0; i--) {
        swap(v, v+i);
        heapify(v, i, 0);
    }
}
