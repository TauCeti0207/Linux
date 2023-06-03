#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    printf("我是一个父进程,我的pid:%d\n",getpid());
    pid_t id = fork();
    if(id == 0)
    {
        //child process
        printf("我是一个子进程,我的pid:%d\n",getpid());
        
        //让子进程执行全新的程序
        char* const argv[] = {(char*)"ls",(char*)"-a",(char*)"-l",(char*)NULL};//指针数组
        //execv("/usr/bin/ls",argv);
        //execlp("ls","ls","-a","-l",NULL);//两个ls 含义不同
        execvp("ls",argv);
        exit(1);//只要执行了exit，意味着execl系列的函数就失败了
    }
    // parent process
    int status = 0;
    int ret = waitpid(id,&status,0);
    if(ret == id)
    { 
        sleep(2);
        printf("父进程等待成功\n");
    }
    return 0;
}

