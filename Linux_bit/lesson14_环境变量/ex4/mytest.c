/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-07 15:05:42
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-07 15:08:29
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ./mytest -a 10 20  传入参数共4个
int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		int x = atoi(argv[2]);
		int y = atoi(argv[3]);
		if (strcmp(argv[1], "-a") == 0)
		{
			printf("%d + %d = %d\n", x, y, x + y);
		}
		else if (strcmp(argv[1], "-s") == 0)
		{
			printf("%d - %d = %d\n", x, y, x - y);
		}
		else if (strcmp(argv[1], "-m") == 0)
		{
			printf("%d * %d = %d\n", x, y, x * y);
		}
		else if (strcmp(argv[1], "-d") == 0 && y != 0)
		{
			printf("%d / %d = %d\n", x, y, x / y);
		}
		else
		{
			printf("please use ./mytest [-a|-s|-m|-d] one_data two_data\n");
		}
	}
	else
	{
		printf("please use ./mytest [-a|-s|-m|-d] one_data two_data\n");
	}
	return 0;
}