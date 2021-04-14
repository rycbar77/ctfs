CC=gcc
CFLAGS=-O3 -s -D_FORTIFY_SOURCE=2 -fstack-protector-all -z relro -z now -z noexecstack

all: maze

easyre: maze.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm maze