CC=g++
CFLAGS=-O3 -s -D_FORTIFY_SOURCE=2 -fstack-protector-all -z relro -z now -z noexecstack

all: easyre

easyre: easyre.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm easyre