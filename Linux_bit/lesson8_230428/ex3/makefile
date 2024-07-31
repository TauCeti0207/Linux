CC=gcc
CFLAGS=-Wall
SOURCES=test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test

all:$(EXECUTABLE) 

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@  

$(OBJECTS):$(SOURCES)   
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY:clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
