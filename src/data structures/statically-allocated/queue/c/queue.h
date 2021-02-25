#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 20

typedef struct queue_ Queue;

typedef int Type;

Queue *queue_init();

Type queue_push(Queue *, Type);
Type queue_pop(Queue *);
Type queue_top(Queue *);

Type queue_empty(Queue *);
Type queue_full(Queue *);

void queue_free(Queue *);

Type check_pointer(void *);


#endif // QUEUE_H
