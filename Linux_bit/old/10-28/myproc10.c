#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <string.h>
#include<sys/wait.h>
int main( )
{
    pid_t id = fork() ;
    if(id == 0)
    {
        int cnt = 5;
        while(1 )
        {
            printf("我是子进程，我正在运行.. .Pid:%d\n", getpid());
            sleep(1);
            cnt--;
            if(!cnt) break;
        }
        exit(113); //设置一个奇怪一点的退出码
    }
    else
    {
        int status = 0;
        printf("我是父进程，pid:%d, 我准备等待子进程了! \n", getpid());
		pid_t ret = waitpid(id, &status, 0);
        if(ret > 0) //正常退出
        {
            printf("wait success, ret : %d, 我所等待子进程的退出码: %d\n", ret, (status>>8)&0xFF);
        }
    }
    return 0;
}
