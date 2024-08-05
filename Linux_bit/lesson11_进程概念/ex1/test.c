/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-05 14:37:27
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-05 14:37:28
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	while (1)
	{
		printf("I am a procee! pid:%d ppid:%d\n", getpid(), getppid());
		sleep(1);
	}
	return 0;
}