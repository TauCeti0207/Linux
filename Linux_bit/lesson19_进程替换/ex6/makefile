.PHONY:all
all:mycmd myexec
mycmd:mycmd.cpp
	g++ -o $@ $^ -std=c++11
myexec:myexec.c
	gcc -o $@ $^ -std=c99
.PHONY:clean
clean:
	rm -f myexec mycmd
