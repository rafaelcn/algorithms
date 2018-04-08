#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "stack.h"


int main(int argc, char **argv) {

    Stack *s = stack_init();

    stack_push(s, 5);
    stack_push(s, 10);

    assert(stack_pop(s) == 10);
    assert(stack_pop(s) == 5);
    assert(stack_empty(s) == true);

    stack_push(s, 12);
    stack_push(s, 15);

    assert(stack_top(s) == 15);
    assert(stack_full(s) == false);
    assert(stack_empty(s) == false);

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        stack_push(s, rand()%100);
    }

    assert(stack_full(s) == true);

    for (int i = 0; i < 20; i++) {
        stack_pop(s);
    }

    assert(stack_empty(s) == true);

    stack_free(s);

    return 0;
}
