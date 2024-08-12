CC=gcc
CFLAGS=-Wall -g -pthread -fopenmp
SOURCES=ticketbooking2.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ticketbooking2

all:$(EXECUTABLE) 

$(EXECUTABLE):$(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@  

.PHONY:clean
clean:
	rm -f *.o $(EXECUTABLE)
