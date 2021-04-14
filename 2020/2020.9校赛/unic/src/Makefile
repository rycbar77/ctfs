CC=gcc
CFLAGS=-O3 -s -D_FORTIFY_SOURCE=2 -fstack-protector-all -z relro -z now -z noexecstack
LDFLAGS += $(shell pkg-config --libs glib-2.0) -pthread -lm -lunicorn
all: unic
unic: unic.c
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm unic