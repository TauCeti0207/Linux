#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t id = fork();
    if (id == 0)
    {
        // child
        while (1)
        {
            printf("I am child process, my pid: %d, my ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else
    {
        while (1)
        {
            printf("I am parent process, my pid: %d, my ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    return 0;
}

