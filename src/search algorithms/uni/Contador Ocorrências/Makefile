CC = gcc
FLAGS = -Wall -pedantic -Og -g -std=c11
SRC = src/*.c # I'm aware of the globbing problems
EXEC = counter.out
DEXEC = counter_debug.out

ifeq ($(OS), Windows_NT)
	EXEC = counter.exe
	DEXEC = counter_debug.exe
endif

all:
	$(CC) $(FLAGS) $(SRC) -o bin/$(EXEC)

debug:
	$(CC) -DDEBUG $(FLAGS) $(SRC) -o bin/$(DEXEC)
