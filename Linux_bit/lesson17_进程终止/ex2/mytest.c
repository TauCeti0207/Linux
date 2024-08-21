/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-21 08:20:11
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-21 08:20:12
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int cnt = 0;
int main()
{
	for (;;)
	{
		pid_t id = fork();
		if (id < 0)
		{
			printf("创建子进程失败... 总共创建%d进程\n", cnt);
			break;
		}
		if (id == 0)
		{
			printf("I am a child... %d, ppid: %d\n", getpid(), getppid());
			sleep(2);
			exit(0); // 创建完就退出进程，子进程活了2s就终止
		}
		cnt++;
	}
	return 0;
}