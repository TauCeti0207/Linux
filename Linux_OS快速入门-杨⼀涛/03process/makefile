CC=gcc
CFLAGS=-Wall -g
SOURCES=helloprocess3.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all:$(EXECUTABLE) 

$(EXECUTABLE):$(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@  

.PHONY:clean
clean:
	rm -f *.o $(EXECUTABLE)
