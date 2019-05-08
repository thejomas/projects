CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic -std=gnu99
EXAMPLES=fibHeap main

.PHONY: all clean

all: $(EXAMPLES)

fibHeap.o: fibHeap.c fibHeap.h
	$(CC) -c fibHeap.c $(CFLAGS)

%: %.c fibHeap.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TESTS) $(EXAMPLES) *.o core
