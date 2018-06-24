#include <stdio.h>
#include <stdlib.h>

#include "file.h"

void usage();

int main(int argc, char **argv) {

    if (argc <= 1) {
        usage();
        exit(0);
    }

    char *filename = argv[1];


    return 0;
}
