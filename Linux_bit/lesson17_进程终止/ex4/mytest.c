/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-21 08:57:48
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-21 09:00:28
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
int main()
{
	int ret = 0;
	char *p = (char *)malloc(1000 * 1000 * 1000 * 4);
	if (p == NULL)

	{
		printf("malloc failed, %d: %s\n", errno, strerror(errno));
		ret = errno;
	}
	else
	{
		printf("malloc success\n");
	}
	return ret;
}
