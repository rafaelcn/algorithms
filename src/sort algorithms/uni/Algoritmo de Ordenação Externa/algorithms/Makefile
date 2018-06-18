CC=gcc
FLAGS=-Wall -pedantic -std=c99
DFLAGS=$(FLAGS) -g -Og
SRC=external_merge.c file.c heap.c

EXEC=external_merge.out
EXEC_P=prof.out

ifeq ($(OS), Windows_NT)
	EXEC=external_merge.exe
endif

all:
	$(CC) $(DFLAGS) $(SRC) -o $(EXEC)
	$(CC) $(DFLAGS) prof.c file.c -o prof.out

mine:
	$(CC) $(DFLAGS) $(SRC) -o $(EXEC)

prof:
	$(CC) $(DFLAGS) prof.c file.c -o prof.out


heap:
	$(CC) $(FLAGS) heap.c heap_test.c -o heap_test.out

clear:
	rm  data/*
