/*
 *
 *                              UTFPR
 *
 * authors: Rafael Campos Nunes & Mikael Messias Pereira
 *
 * This is an implementation of a min-heap with a heap sort, mind yourself that
 * this is used in the classify phase and intercalate phase of the external
 * sort.
 */
#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>

struct heap_element {
    int key;
    int weight;
};

struct priority_queue {
    // The vector that holds the heap inside the structure
    struct heap_element *vector;

    // uint16_t = 2^16 not signalized.

    // The current index of the heap
    uint16_t index;
    // The current size of the heap
    uint16_t size;

    // Mostly of the time the size == index but we may modify the index as
    // needed to fill and remove elements, that will be a more reliable
    // source of information.
};

typedef struct priority_queue Heap;
typedef struct heap_element HeapElement;

/**
 * @brief Creates a new priority queue and returns it to the caller with the
 * initialized data.
 */
Heap *heap_make(int);
/**
 * @brief Creates a heap from an integer pointer and sorts the vector
 * underlying that pointer.
 */
void heap_sort(Heap *);
/**
 * @brief Creates a heap data structure from an integer pointer but it doesn't
 * sorts it.
 */
void heapify(HeapElement *, int, int);
/**
 * @brief Takes a Heap as input and creates a new HeapElement inserting it
 * index specified as its fourth parameter on the heap.
 *
 */
void sift_up_i(Heap *, int, int, int);
/**
 * @brief Takes a Heap as input and creates a new HeapElement inserting it on
 * the Heap and sorting the entire Heap
 */
void sift_up(Heap *, int, int);
/**
 * @brief Returns the first element of the heap - a HeapElement - rebuilding
 * the heap soon after that.
 */
HeapElement sift_down(Heap *);

#endif // HEAP_H
