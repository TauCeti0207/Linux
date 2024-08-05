/*************************************************************************
        > File Name: mytest.c
        > Author: tauceti0207
        > Mail: 2076188013@qq.com
        > Created Time: Mon May  1 22:18:15 2023
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main()
{
    while(1)
    {
        printf("I am a process... my pid is %d\n", getpid());
        sleep(100);
    }
    return 0;
}
