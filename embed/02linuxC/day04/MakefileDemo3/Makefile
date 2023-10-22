CC=gcc
CFLAGS=-Wall -I include
VPATH=src1:src2:main
f1:f1.o f2.o main.o
	$(CC) $(CFLAGS) $^ -o $@
.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;rm f1
