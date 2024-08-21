/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-21 09:50:02
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-21 11:49:12
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t id = fork();
	if (id < 0)
	{
		perror("fork");
		return 1;
	}
	else if (id == 0)
	{
		// child
		int cnt = 5;
		while (cnt)
		{
			printf("我是子进程，我正在运行...pid:%d ppid:%d cnt:%d\n", getpid(), getppid(), cnt);
			cnt--;
			sleep(1);
			// int *p = NULL;
			// *p = 10;
		}
		exit(111);
	}
	else
	{
		// parrent
		int cnt = 10;
		while (cnt)
		{
			printf("我是父进程，我正在运行...我准备等待子进程了! pid:%d ppid:%d cnt:%d\n", getpid(), getppid(), cnt);
			cnt--;
			sleep(1);
		}
		int status = 0;
		pid_t ret = waitpid(id, &status, 0);
		if (ret < 0)
		{
			printf("等待失败\n");
		}
		else if (ret == id)
		{
			// 7f 0111 1111 低7位表示的就是退出信号
			// printf("等待成功，ret: %d, exit sig: %d, exit code: %d\n", ret, status & 0x7F, (status >> 8) & 0xFF);

			if (WIFSIGNALED(status))
			{
				printf("子进程被信号终止，信号: %d\n", WTERMSIG(status));
			}
			else if (WIFEXITED(status))
			{
				printf("子进程正常退出，退出码: %d\n", WEXITSTATUS(status));
			}
		}
	}
	return 0;
}