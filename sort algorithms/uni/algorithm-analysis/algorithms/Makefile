CC=g++
FLAGS=-Wall -pedantic -std=c++11
DFLAGS=-Wall -pedantic -std=c++11 -g
EXEC=test.out
DEXEC=test_debug.out

ifeq ($(OS),Windows_NT)
	EXEC=test.exe
	DEXEC=test_debug.exe
endif

SRC=main.cpp random.cpp csv.cpp algorithms.cpp timer.cpp logarithmic/shell.cpp \
quadratic/bubble.cpp quadratic/insertion.cpp quadratic/selection.cpp \
logarithmic/quick.cpp logarithmic/heap.cpp logarithmic/merge.cpp

all:
	$(CC) $(FLAGS) $(SRC) -o $(EXEC)

debug:
	$(CC) $(DFLAGS) $(SRC) -o $(DEXEC)

clear:
	rm $(EXEC)
