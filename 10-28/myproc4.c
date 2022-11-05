#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> 
int g_val = 100;
int main(int argc, char* argv[], char* env[])
{
    pid_t id = fork();
    if(id == 0)
    {
        // child
        int flag = 0;
        while(1)
        {
            printf("child:%d ppid:%d g_val:%d &g_val:%p\n\n", getpid(), getppid(), g_val, &g_val);
            sleep(1);
            flag++;
            if(flag == 5)
            {
                g_val = 200;
                printf("I am chlid, g_val has been modified\n");
            }
        }
    }
    else 
    {
        // parent
        while(1)
        {
            printf("parent:%d ppid:%d g_val:%d &g_val:%p\n\n", getpid(), getppid(), g_val, &g_val);
            sleep(2);
        }
    }
    return 0;
}
