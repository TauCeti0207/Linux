#include "mystdio.h"
#include <unistd.h>

#define myfile "log.txt"

int main()
{
	// 打开文件以附加模式写入，如果文件不存在则创建
	_FILE *fp = _fopen(myfile, "a");
	// 检查文件是否成功打开
	if (fp == NULL)
		return 1;

	// 定义要写入文件的消息
	const char *msg = "hello world\n";
	// 定义消息需要写入的次数
	int cnt = 5;
	// 循环写入消息到文件，每次写入后等待1秒
	while (cnt)
	{
		// 向文件写入消息
		_fwrite(fp, msg, strlen(msg));
		sleep(1);
		cnt--;
	}

	// 关闭文件
	_fclose(fp);

	return 0;
}
