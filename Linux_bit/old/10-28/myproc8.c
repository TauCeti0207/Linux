#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <string.h>


int main()
{
    printf("hello world"); //没有\n还留在缓冲区中
    sleep(2);
    _exit(0);//exit退出时会刷新缓冲区
    return 10;
}
