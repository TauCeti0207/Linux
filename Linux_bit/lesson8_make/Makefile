hello:main.o test.o
	gcc main.o test.o -o hello
main.o:main.c
	gcc -c main.c -o main.o # 只写 gcc -c main.c 也行
test.o:test.c
	gcc -c test.c -o test.o
.PHONY:clean
clean:
	rm -f *.o hello
