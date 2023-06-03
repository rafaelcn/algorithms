#ifndef ASSERTIONS_H
#define ASSERTIONS_H

#include <stdio.h>

#include "matrix.h"
#include "macros.h"

/**
 * @brief Asserts a value to be equal a expected value.
 */
#ifdef __linux__
#define ASSERT(v, e, m)                                                 \
    printf("\n%s%s%s\n", ANSI_COLOR_YELLOW, (m), ANSI_COLOR_RESET);     \
    if ((v) != (e)) {                                                   \
        printf("%sGot: %d. Expect: %d %s", ANSI_COLOR_RED, (v), (e),    \
               ANSI_COLOR_RESET);                                       \
    } else {                                                            \
        printf("%sGot: %d. Expect: %d. %s", ANSI_COLOR_GREEN, (v), (e), \
               ANSI_COLOR_RESET);                                       \
    };
#elif
#define ASSERT(v, e, m)                                                 \
    printf("\n%s\n", (m));                                              \
    if ((v) != (e)) {                                                   \
        printf("Got: %d. Expect: %d", (v), (e));                        \
    } else {                                                            \
        printf("Got: %d. Expect: %d.", (v), (e));                       \
    };
#endif // __linux__


#endif // ASSERTIONS_H
