#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * Structure that defines a Queue.
 */
struct queue_ {
    /// Points to the last value inserted on the queue.
    int head;
    /// Points to the current value at which will be removed.
    int idx_ptr;
    /// The data of the structure.
    int data[QUEUE_SIZE];
};

static void pferror(char *m, int l) {
    fprintf(stderr, "\n---> %s | Queue.c line: %d\n\n", m, l);
}

Queue *queue_init() {
    Queue *q = (Queue *) malloc(sizeof(Queue));

    if (!check_pointer(q)) {
        pferror("Couldn't allocate the Queue. Exiting now.", __LINE__);
        exit(1);
    }

    q->head = -1;
    // it starts by pointing to the 0 element of the Queue
    q->idx_ptr = 0;

    int i;
    for (i = 0; i < QUEUE_SIZE; i++) {
        q->data[i] = 0;
    }

    return q;
}

int queue_push(Queue *q, int value) {
    if (check_pointer(q)) {
        if (!queue_full(q)) {
            q->head++;
            q->data[q->head] = value;

            return 1;
        }
    }

    return 0;
}

int queue_pop(Queue *q) {
    if (check_pointer(q)) {
        if (!queue_empty(q)) {
            int v = q->data[q->idx_ptr];
            q->idx_ptr++;
            return v;
        } else {
            pferror("Queue is empty.", __LINE__);
        }
    }

    return -1;
}

int queue_empty(Queue *q) {
    if (check_pointer(q)) {
        if (q->idx_ptr > QUEUE_SIZE || q->idx_ptr == -1 ||
            q->idx_ptr > q->head) {
            return 1;
        }
    }

    return 0;
}

int queue_full(Queue *q) {
    if (check_pointer(q)) {
        if (q->head == QUEUE_SIZE - 1) {
            return 1;
        }
    }

    return 0;
}

void queue_free(Queue *q) {
    free(q);
}

int check_pointer(void *p) {
    if (p != NULL) {
        return 1;
    }

    return 0;
}
