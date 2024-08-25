CC=gcc
CFLAGS=-Wall -g -pthread -std=c99
SOURCES=myshell.c
EXECUTABLE=$(patsubst %.c,%,$(SOURCES))
OBJECTS=$(SOURCES:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@


.PHONY: clean
clean:
	rm -f *.o $(EXECUTABLE)