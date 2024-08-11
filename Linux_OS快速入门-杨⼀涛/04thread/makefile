CC=gcc
CFLAGS=-Wall -g -pthread -fopenmp
SOURCES=hellothread2.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=hellothread2

all:$(EXECUTABLE) 

$(EXECUTABLE):$(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@  

.PHONY:clean
clean:
	rm -f *.o $(EXECUTABLE)
