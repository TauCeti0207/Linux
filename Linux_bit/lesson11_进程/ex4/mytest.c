/*************************************************************************
        > File Name: mytest.c
        > Author: tauceti0207
        > Mail: 2076188013@qq.com
        > Created Time: Mon May  1 23:53:49 2023
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t id = fork();
    if(id == 0){
        // child
        int cnt = 0;
        while(1){
            printf("I am child process, %d S my pid: %d, my ppid: %d\n", cnt++, getpid(), getppid());
            sleep(1);
        }
        printf("I am child process, I am zombie...\n");
    }else{
        // father
        int cnt = 5;
        while(cnt){
            printf("I am parent process, %d S\n", cnt--);
            sleep(1);
        }
        printf("father quit...\n");
		exit(0);
    }
    return 0;
}
