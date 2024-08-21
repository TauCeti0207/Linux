/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-21 08:30:00
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-21 08:31:26
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	for (int i = 0; i < 100; ++i)
	{
		printf("%d:%s\n", i, strerror(i));
	}
	return 0;
}
