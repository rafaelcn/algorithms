GCC = gcc
CFLAGS = -std=c99 -Wall -W -pedantic
CDFLAGS = -std=c99 -Wall -W -pedantic -DDEBUG -g

EXEC = matrix.out

all:
	$(GCC) $(CFLAGS) matrix.c main.c -o $(EXEC)

debug:
	$(GCC) $(CDFLAGS) matrix.c main.c -o $(EXEC)

clean:
	rm matrix.out
