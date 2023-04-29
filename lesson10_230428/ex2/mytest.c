/*************************************************************************
        > File Name: mytest.c
        > Author: tauceti0207
        > Mail: 2076188013@qq.com
        > Created Time: Fri Apr 28 20:55:00 2023
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    while(1)
    {
        printf("I am a procee! pid:%d ppid:%d\n", getpid(),getppid());
        sleep(1);
    }
    return 0;
}
