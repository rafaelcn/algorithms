#include "circular_queue.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The structure that defines a circular queue.
 */
struct cqueue {
    ///
    int head;
    ///
    int tail;
    ///
    int data[CQUEUE_SIZE];
};


static void pferror(const char* m, int l) {
    fprintf(stderr, "\n\n--> %s | on %s line %d", m,  __FILE__, l);
}

CircularQueue* queue_init() {
    CircularQueue* cq = malloc(sizeof(CircularQueue));

    if (check_pointer(cq)) {
        pferror("Could not allocate memory for circular queue.", __LINE__);
        exit(1);
    }

    return cq;
}

int queue_push(CircularQueue* cq, int v) {
    if (check_pointer(cq)) {
        pferror("Circular queue given to push is null", __LINE__);
        return 0;
    }

    cq->tail += 1 % CQUEUE_SIZE;
    cq->data[cq->tail] = v;

    return 1;
}

Value queue_pop(CircularQueue* cq) {
    Value v;

    v.v = NULL;

    if (check_pointer(cq)) {
        pferror("Circular queue given to pop is null", __LINE__);
        return v;
    }

    if (queue_empty(cq)) {
        pferror("Circular queue is empty", __LINE__);
        return v;
    }

    v.v = &cq->data[cq->head];
    cq->head += 1 % CQUEUE_SIZE;

    return v;
}

Value queue_top(CircularQueue *cq) {
    return queue_pop(cq);
}

int queue_empty(CircularQueue *cq) {
    // not sure if entirely complete/correct
    return queue_size(cq) == 0;
}

int queue_full(CircularQueue *cq) {
    return queue_size(cq) == CQUEUE_SIZE;
}

int queue_size(CircularQueue *cq) {
    return (CQUEUE_SIZE - cq->head + cq->tail) % CQUEUE_SIZE;
}

void queue_free(CircularQueue *cq) {
    free(cq);
}

int check_pointer(void *p) {
    if (p != NULL) {
        return 1;
    }

    return 0;
}
