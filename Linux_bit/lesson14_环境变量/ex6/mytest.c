/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-07 15:52:25
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-07 15:52:25
 */
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *env[])
{
	extern char **environ; // C提供的全局变量 指向字符指针数组的指针
	for (int i = 0; environ[i]; ++i)
	{
		printf("env[%d]%s\n", i, environ[i]);
	}
	return 0;
}