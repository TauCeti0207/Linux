CC=gcc
CFLAGS=-Wall -g -pthread -fopenmp
SOURCES=sample.c
EXECUTABLE=$(patsubst %.c,%,$(SOURCES))
OBJECTS=$(SOURCES:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@


.PHONY: clean
clean:
	rm -f *.o $(EXECUTABLE)