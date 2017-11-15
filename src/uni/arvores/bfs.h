#ifndef BFS_H
#define BFS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct filesystem Filesystem;

void bfs_init();

void bfs_load(FILE* virtual_filesystem);


#endif // BFS_H
