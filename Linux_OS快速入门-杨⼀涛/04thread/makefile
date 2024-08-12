CC=gcc
CFLAGS=-Wall -g -pthread -fopenmp
SOURCES=hellothread3.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=hellothread3

all:$(EXECUTABLE) 

$(EXECUTABLE):$(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@  

.PHONY:clean
clean:
	rm -f *.o $(EXECUTABLE)
