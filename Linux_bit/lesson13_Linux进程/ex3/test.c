/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-06 14:11:31
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-06 14:11:31
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
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
		exit(0); // 子进程正常退出
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