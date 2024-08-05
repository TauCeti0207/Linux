/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-05 20:05:58
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-05 20:06:43
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