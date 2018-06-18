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

typedef heap_element HeapElement;

/**
 * @brief Creates a heap from an integer pointer and sorts the vector
 * underlying that pointer.
 */
void heap(int *, int);
/**
 * @brief Creates a heap data structure from an integer pointer but it doesn't
 * sorts it.
 */
void heapify(int *, int, int);



#endif // HEAP_H
