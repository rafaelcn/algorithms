/**
 * MIT License
 *
 * Copyright (c) 2017 Rafael C. Nunes
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE  SOFTWARE.
 */

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STACK_MAX_SIZE 20

struct stack {
    int index;
    Type v[STACK_MAX_SIZE];
};

static void pferror(char *m, int line) {
    fprintf(stderr, "\n\nError: %s | On line %d from file %s", m, line,
            __FILE__);
}

static int check_pointer(void *p) {
    return p != NULL;
}

Stack *stack_init() {
    Stack *s = malloc(sizeof(Stack));

    if (s == NULL) {
        pferror("The stack couldn't be allocated", __LINE__);
        exit(EXIT_FAILURE);
    }

    s->index = -1;

    return s;
}

Type stack_top(Stack *s) {
    if (!stack_empty(s)) {
        Type tmp = s->v[s->index];
        s->index--;

        return tmp;
    }

    pferror("Stack is empty, cannot top", __LINE__);
    return INT_MIN;
}

Type stack_pop(Stack *s) {
    if (!stack_empty(s)) {
        s->index--;
        // Quite weird, another way would be to store it on a tmp variable.
        return s->v[s->index+1];
    }


    pferror("Stack is empty, cannot pop", __LINE__);
    return (Type) INT_MIN;
}


int stack_push(Stack *s, Type v) {
    if (!stack_full(s)) {
        s->index++;
        s->v[s->index] = v;

        return 0;
    }

    // Value couldn't be pushed, returning error.
    pferror("Stack is full, cannot push", __LINE__);
    return -1;
}

int stack_empty(Stack *s) {
    if (check_pointer) {
        return s->index == -1;
    }

    pferror("Null pointer given", __LINE__);
}

int stack_full(Stack *s) {
    if (check_pointer) {
        return s->index == STACK_MAX_SIZE;
    }

    pferror("Null pointer given", __LINE__);
}

void stack_free(Stack *s) {
    free(s);
}
