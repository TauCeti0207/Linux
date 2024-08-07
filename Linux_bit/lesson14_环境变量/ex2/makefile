CC=gcc
CFLAGS=-Wall -g
SOURCES=mytest.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mytest

all:$(EXECUTABLE) 

$(EXECUTABLE):$(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@  

.PHONY:clean
clean:
	rm -f *.o $(EXECUTABLE)
