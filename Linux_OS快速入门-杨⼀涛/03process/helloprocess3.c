/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-09 22:22:03
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-09 22:35:07
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t cid; // child pid

	printf("Before fork Process id:%d\n", getpid());

	int value = 100;

	cid = fork();

	if (cid == 0)
	{
		printf("Child process id (my parent pid is %d):%d\n", getppid(), getpid());
		for (int i = 0; i < 3; i++)
		{
			printf("hello(%d)\n", value--);
		}
		sleep(3);
	}
	else
	{
		printf("Parent Process id: %d\n", getpid());
		for (int i = 0; i < 3; i++)
		{
			printf("world(%d)\n", value++);
		}

		wait(NULL); // 等待子进程结束
					// 如果父进程不等子进程，父进程运行完就return 子进程就会变成孤儿进程，就会被1号进程/init进程接管
	}

	return 0;
}