//myexec.c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    //环境变量指针声明
    extern char** environ;
    printf("我是一个父进程,我的pid:%d\n",getpid());
    pid_t id = fork();
    if(id == 0)
    {
        //child process
        printf("我是一个子进程,我的pid:%d\n",getpid());
        char* const env_[] = {(char*)"MYPATH=YouCanSeeMe!!",NULL};
        char* myargv[] = {"mycmd",NULL};
        char* myenvp[] = {(char*)"MYPATH=YouCanSeeMe!!",NULL};
        char* const argv[] = {(char*)"ls",(char*)"-a",(char*)"-l",(char*)NULL};//指针数组
        //execv("/usr/bin/ls",argv);
        //execlp("ls","ls","-a","-l",NULL);//两个ls 含义不同
        execvpe("./mycmd",myargv,environ);
        //execve("./mycmd", myargv, environ);
        //execve("./mycmd", myargv, myenvp);
        //e:覆盖式的添加环境变量给目标进程
        //execle("./mycmd","mycmd",NULL,environ);
        //execle("./mycmd","mycmd",NULL,env_);
        //execl("/home/yzq0207/Desktop/Linux/lesson17_230523/ex6/mycmd","mycmd",NULL);
        //execl("./mycmd","mycmd",NULL);//相对路径也可以的
        //execl("/usr/bin/python3","python3","helloPY.py",NULL);
        //execl("/usr/bin/bash","bash","test.sh",NULL);
        //让子进程执行全新的程序
        //char* const argv[] = {(char*)"ls",(char*)"-a",(char*)"-l",(char*)NULL};//指针数组
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
