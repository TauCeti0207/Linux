CC=gcc
CFLAGS=-Wall -g
SOURCES=process4.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=process4

all:$(EXECUTABLE) 

$(EXECUTABLE):$(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@  

.PHONY:clean
clean:
	rm -f *.o $(EXECUTABLE)
