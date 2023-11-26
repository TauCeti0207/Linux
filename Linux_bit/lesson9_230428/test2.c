#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t id = fork();
    if (id == 0)
    {
        // child
        int cnt = 5;
        while (cnt)
        {
            printf("I am child process, %d S\n", cnt--);
            sleep(1);
        }
        printf("I am child process, I am zombie...\n");
        exit(0);
    }
    else
    {
        // father
        while (1)
        {
            sleep(1);
        }
    }
    return 0;
}