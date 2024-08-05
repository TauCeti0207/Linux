/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-05 14:37:43
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-05 15:40:35
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t id = fork();
	printf("hello world! pid: %d\n", id);
	sleep(1);
	return 0;
}