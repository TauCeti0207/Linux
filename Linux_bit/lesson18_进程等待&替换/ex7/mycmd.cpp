#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef void (*handler_t)();//Function pointer type
std::vector<handler_t> handlers;//function set

void fun1()
{
    printf("hello I am function1\n");
}
void fun2()
{
    printf("hello I am function2\n");
}
void Load()//load function
{
    handlers.push_back(fun1);
    handlers.push_back(fun2);
}
int main()
{
    pid_t id = fork();

    if (id == 0)
    {
        // 子进程
        while (1)
        {
            printf("我是子进程，我的pid：%d，我的ppid：%d\n", getpid(), getppid());
            sleep(1);
        }
        exit(1004);
    }
    else if (id > 0)
    {
        // 父进程
        int status = 0;
        while (1)
        {
            pid_t ret = waitpid(-1, &status, WNOHANG); // 基于非阻塞的轮询等待方案：WNOHANG
            if (ret > 0)
            {
                printf("等待成功！%d，exit sig：%d，exit code：%d\n", ret, status & 0x7F, (status >> 8) & 0xFF);
                break;
            }
            else if (ret == 0)
            {
                // 等待成功了，但是子进程没有退出
                printf("子进程未准备好，父进程做其他事情...\n");
                if(handlers.empty()) Load();
                for(auto f : handlers)
                {
                    f();//callback handles the corresponding function
                }
                sleep(1);
            }
            else
            {
                // 出错了
                printf("error1\n");
            }
        }
    }
    else
    {
        // 错误情况
        printf("error2\n");
    }
    return 0;
}
