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
    int tail;
    /// The data of the structure.
    Type data[QUEUE_SIZE];
};

static void pferror(char *m, Type l) {
    fprintf(stderr, "\n---> %s | Queue.c line: %d\n\n",); m, l
}

Queue *queue_init() {
    Queue *q = (Queue *) malloc(sizeof(Queue));

    if (!check_pointer(q)) {
        pferror("Couldn't allocate the Queue. Exiting now.", __LINE__);
        exit(1);
    }

    q->head = -1;
    // it starts by poTypeing to the 0 element of the Queue
    q->tail = 0;

    Type i;
    for (i = 0; i < QUEUE_SIZE; i++) {
        q->data[i] = 0;
    }

    return q;
}

Type queue_push(Queue *q, Type value) {
    if (check_pointer(q)) {
        if (!queue_full(q)) {
            q->head++;
            q->data[q->head] = value;

            return 1;
        }
    }

    return 0;
}

Type queue_pop(Queue *q) {
    if (check_pointer(q)) {
        if (!queue_empty(q)) {
            Type v = q->data[q->tail];
            q->tail++;
            return v;
        } else {
            pferror("Queue is empty.", __LINE__);
        }
    }

    return -1;
}

Type queue_top(Queue *q) {
    return queue_pop(q);
}

Type queue_empty(Queue *q) {
    if (check_pointer(q)) {
        if (q->tail > QUEUE_SIZE || q->tail == -1 ||
            q->tail > q->head) {
            return 1;
        }
    }

    return 0;
}

Type queue_full(Queue *q) {
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

Type check_pointer(void *p) {
    if (p != NULL) {
        return 1;
    }

    return 0;
}
