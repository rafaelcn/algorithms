#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "queue.h"


int main(int argc, char **argv) {

    Queue *s = queue_init();

    queue_push(s, 5);
    queue_push(s, 10);

    assert(queue_pop(s) == 10);
    assert(queue_pop(s) == 5);
    assert(queue_empty(s) == true);

    queue_push(s, 12);
    queue_push(s, 15);

    assert(queue_top(s) == 15);
    assert(queue_full(s) == false);
    assert(queue_empty(s) == false);

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        queue_push(s, rand()%100);
    }

    assert(queue_full(s) == true);

    for (int i = 0; i < 20; i++) {
        queue_pop(s);
    }

    assert(queue_empty(s) == true);

    queue_free(s);

    return 0;
}
