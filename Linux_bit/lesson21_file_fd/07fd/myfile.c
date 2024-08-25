/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-25 12:59:50
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-25 13:03:07
 */
#include <stdio.h>
#include <unistd.h>

int main1()
{
	char buf[128] = {0};					   // 初始化缓冲区
	ssize_t s = read(0, buf, sizeof(buf) - 1); // 从标准输入读取数据

	if (s > 0)
	{
		buf[s] = '\0';	   // 确保字符串以空字符结尾
		printf("%s", buf); // 打印读取到的字符串
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	char str[] = "hello world\n";
	printf("sizeof str:%ld\n", sizeof(str));
	write(1, str, sizeof(str) - 1);
	return 0;
}
