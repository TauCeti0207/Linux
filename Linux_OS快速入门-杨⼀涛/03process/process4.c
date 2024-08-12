/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-11 21:32:22
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-11 21:35:11
 */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;

	/* fork a child process */
	pid = fork();

	if (pid < 0)
	{
		/* error occurred */
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if (pid == 0)
	{
		/* child process */
		// execlp()会替换当前进程的内存空间，使其变成新程序的内存空间
		execlp("/bin/ls", "ls", NULL);

		/* If execlp() is successful, this line will not be executed */
		fprintf(stderr, "execlp() failed\n");
		return 1;
	}
	else
	{
		/* parent process */
		int status;

		/* parent will wait for the child to complete */
		wait(&status);

		if (WIFEXITED(status))
		{
			printf("Child completed with exit status %d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("Child did not terminate normally\n");
		}
	}

	return 0;
}