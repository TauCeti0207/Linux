#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int cnt = 0;
int main()
{
    for (;;)
    {
        pid_t id = fork();
        if (id < 0)
        {
            printf("创建子进程失败... 总共创建%d进程\n", cnt);
            break;
        }
        if (id == 0)
        {
            printf("I am a child... %d\n", getpid());
            sleep(2);
            exit(0); // 创建完就退出进程，子进程活了2s就终止
        }
        cnt++;
    }
}