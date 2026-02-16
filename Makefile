CC=gcc
CFLAGS=-Wall -O2

all: lab3

lab3: main.o stack.o sort.o fileio.o
	$(CC) $(CFLAGS) main.o stack.o sort.o fileio.o -o lab3

clean:
	rm -f *.o lab3

