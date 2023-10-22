OBJS=f1.o f2.o
OBJS+=main.o
CFLAGS=-c -Wall -O -g
test:$(OBJS)
	gcc $(OBJS) -o $@ #equal to test
f1.o:f1.c
	gcc $(CFLAGS) $^ -o $@ #$^ equal to f1.c  the first file
f2.o:f2.c
	gcc $(CFLAGS) $< -o $@ #$@ equal to f2.o  $< equal to f2.c
main.o:main.c
	gcc $(CFLAGS) $< -o $@
.PHONY:clean
clean:
	rm $(OBJS) test
