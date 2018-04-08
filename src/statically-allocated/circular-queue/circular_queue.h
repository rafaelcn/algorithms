#ifndef CQUEUE_H
#define CQUEUE_H

#define CQUEUE_SIZE 10

/**
 * A structure to encapsulate the ~optional~ return condition, the value
 * returned by a function might be NULL or not.
 */
struct value {
    int *v;
};

typedef struct value Value;

typedef struct cqueue CircularQueue;

/**
 * @brief
 */
CircularQueue* queue_init();

/**
 * @brief
 */
int queue_push(CircularQueue*, int);

/**
 * @brief
 */
Value queue_pop(CircularQueue*);

/**
 * @brief
 */
Value queue_top(CircularQueue*);

/**
 * @brief
 */
int queue_empty(CircularQueue*);

/**
 * @brief
 */
int queue_full(CircularQueue*);

/**
 * @brief
 */
int queue_size(CircularQueue*);

/**
 *
 */
void queue_free(CircularQueue*);

/**
 * @brief
 */
int check_pointer(void *);


#endif // CQUEUE_H
