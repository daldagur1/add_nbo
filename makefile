CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

all: gilmake

sum_numbers: gilmake.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f sum_numbers
