/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-05 20:05:58
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-06 13:57:27
 */
#include <stdio.h>
#include <unistd.h>
int main()
{
	while (1)
	{
		printf("I am a process... my pid is %d\n", getpid());
		sleep(1);
	}
	return 0;
}