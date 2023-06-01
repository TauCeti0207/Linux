#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("我是一个进程,我的pid:%d\n",getpid());
    //ls -a -l
    execl("/usr/bin/ls","ls","-a","-l",NULL);//with options
    //execl("/usr/bin/top","top",NULL);//without options
    printf("我是一个进程,我执行完毕了,我的pid:%d\n",getpid());
    return 0;
}
