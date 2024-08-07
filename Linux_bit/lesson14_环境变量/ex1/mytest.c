/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-05 20:05:58
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-06 23:05:19
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
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
			printf("I am a child... my pid is %d\n", getpid());
			sleep(2);
			exit(0); // 创建完就退出进程，子进程活了2s就终止
		}
		cnt++;
	}
}