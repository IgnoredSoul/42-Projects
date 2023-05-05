CC=gcc
CFLAGS=-Wall -Wextra -pedantic

all: phantom

phantom: phantom.c phantom.h
	$(CC) $(CFLAGS) -o $@ phantom.c

clean:
	rm -f phantom
