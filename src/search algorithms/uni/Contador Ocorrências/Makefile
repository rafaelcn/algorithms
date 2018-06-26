CC = gcc
FLAGS = -Wall -pedantic -Og -g -std=c99
SRC = src/*.c # I'm aware of the globbing problems
EXEC = counter.out

ifeq ($(OS), Windows_NT)
	EXEC = counter.exe
endif

all:
	$(CC) $(FLAGS) $(SRC) -o bin/$(EXEC)
