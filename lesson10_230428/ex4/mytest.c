/*************************************************************************
        > File Name: mytest.c
        > Author: tauceti0207
        > Mail: 2076188013@qq.com
        > Created Time: Sat Apr 29 10:03:12 2023
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t id = fork();
    if(id == 0){
        //child
        while(1){
            printf("I am child process, my pid: %d, my ppid: %d\n",getpid(), getppid());
            sleep(1);
        }
    }else{
        while(1){
            printf("I am parent process, my pid: %d, my ppid: %d\n",getpid(), getppid());
            sleep(1);
        }
    }
    return 0;
}
