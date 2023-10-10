#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    while(1)
    {
        printf("hello pid:%d ppid:%d myenv:%s\n",getpid(), getppid(), getenv("yzq0207"));
        sleep(1);
    }
    return 0;
}
