/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-05 20:05:58
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-07 14:46:39
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *id = getenv("USER");
	if (strcmp(id, "yzq0207") != 0)
	{
		printf("permission denied\n");
		return 0;
	}
	printf("sucess...\n");
	return 0;
}