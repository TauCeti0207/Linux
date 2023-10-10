#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <string.h>

void fun()
{
    printf("hello fun\n");
    exit(111);
}

int main()
{
    exit(222);
    fun();
    return 10;
}
