CC=gcc
FLAGS=-Wall -pedantic -std=c99
DFLAGS=$(FLAGS) -g -Og
SRC=external_merge.c file.c heap.c

EXEC=external_merge.out

ifeq ($(OS), Windows_NT)
	EXEC=external_merge.exe
endif

all:
	$(CC) $(DFLAGS) $(SRC) -o $(EXEC)

mine:
	$(CC) $(DFLAGS) $(SRC) -o $(EXEC)

heap:
	$(CC) $(DFLAGS) heap.c heap_test.c -o heap_test.out

clear:
	rm  data/*
