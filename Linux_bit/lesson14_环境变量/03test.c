#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

/* EXAMPLES
       The  following  program  demonstrates the use of fork(2) and waitpid().  The program creates a child process.  If no command-line argument is supplied to the program, then the child suspends its execution
       using pause(2), to allow the user to send signals to the child.  Otherwise, if a command-line argument is supplied, then the child exits immediately, using the integer supplied on the command line as  the
       exit status.  The parent process executes a loop that monitors the child using waitpid(), and uses the W*() macros described above to analyze the wait status value.

       The following shell session demonstrates the use of the program:

           $ ./a.out &   // & 符号用于在后台运行程序
           Child PID is 32360
           [1] 32359
           $ kill -STOP 32360
           stopped by signal 19
           $ kill -CONT 32360
           continued
           $ kill -TERM 32360
           killed by signal 15
           [1]+  Done                    ./a.out
           $ */
int main(int argc, char *argv[])
{
    pid_t cpid, w;
    int wstatus;

    cpid = fork();
    if (cpid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0)
    { /* Code executed by child */
        printf("Child PID is %jd\n", (intmax_t)getpid());
        if (argc == 1)
            pause(); /* Wait for signals */
        _exit(atoi(argv[1]));
    }
    else
    { /* Code executed by parent */
        do
        {
            w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
            if (w == -1)
            {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
            if (WIFEXITED(wstatus))
            {
                printf("exited, status=%d\n", WEXITSTATUS(wstatus));
            }
            else if (WIFSIGNALED(wstatus))
            {
                printf("killed by signal %d\n", WTERMSIG(wstatus));
            }
            else if (WIFSTOPPED(wstatus))
            {
                printf("stopped by signal %d\n", WSTOPSIG(wstatus));
            }
            else if (WIFCONTINUED(wstatus))
            {
                printf("continued\n");
            }
        } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
        exit(EXIT_SUCCESS);
    }
}