CC=g++
CFLAGS=-static -O3 -s -D_FORTIFY_SOURCE=2 -fstack-protector-all -z relro -z now -z noexecstack

all: simple_unpack

simple_unpack: simple_unpack.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm simple_unpack