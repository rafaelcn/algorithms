#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 20

typedef struct queue_ Queue;

/**
 *
 */
Queue *queue_init();

int queue_push(Queue *, int);
int queue_pop(Queue *);

int queue_empty(Queue *);
int queue_full(Queue *);

void queue_free(Queue *);

int check_pointer(void *);


#endif // QUEUE_H
