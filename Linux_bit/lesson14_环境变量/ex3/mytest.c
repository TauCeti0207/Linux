/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-05 20:05:58
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-07 14:49:02
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	while (1)
	{
		printf("hello pid:%d ppid:%d myenv:%s\n", getpid(), getppid(), getenv("yzq0207"));
		sleep(1);
	}
	return 0;
}