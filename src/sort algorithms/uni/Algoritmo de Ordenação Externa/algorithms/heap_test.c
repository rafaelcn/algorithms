#include <stdio.h>
#include <assert.h>

#include "heap.h"

int main(void) {

    int v[] = {6, 2, 4, 3, 1, 5};
    int s[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    heap(v, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    for (int i = 0; i < n; i++) {
        assert(v[i] == s[i]);
    }

    return 0;
}
