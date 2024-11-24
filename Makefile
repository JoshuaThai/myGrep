CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: mygrep

mygrep: main.o grep.o
	$(CC) $(CFLAGS) -o mygrep main.o grep.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

grep.o: grep.c
	$(CC) $(CFLAGS) -c grep.c -o grep.o

clean:
	rm -f mygrep *.o