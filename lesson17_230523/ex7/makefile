.PHONY:all
all:mycmd myexec
mycmd:mycmd.cpp
	g++ -o $@ $^
myexec:myexec.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -f myexec mycmd
