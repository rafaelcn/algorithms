#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "../linked_list.h"
#include "../iterator.h"

struct list_s {
    char value[64];
    struct list_s *next;
};

typedef struct list_s list_t;

int main(int argc, char **argv) {

    list_t *list = NULL;
    list = list_push(list_push(list_push(list_push(list, "something"), "campos"), "nunes"),
                     "rafael");

    iterator_t *it = iterator_new(list);

    char *words[4];
    words[0] = "something";
    words[1] = "campos";
    words[2] = "nunes";
    words[3] = "rafael";

    size_t i = 0;

    while (iterator_next(it)) {
        char *word = iterator_eval(it);

        assert(strcmp(words[i], word) == 0);

        printf("%s\n", word);
        i++;
    }

    return 0;
}
