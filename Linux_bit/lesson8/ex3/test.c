#include <stdio.h>
#include <unistd.h>
int main()
{
	int cnt = 10;
	while (cnt)
	{
		// 2d 表示2个占位符，- 表示左对齐
		printf("%-2d\r", cnt--); // 让光标移动到最开始，覆盖之前的显示
		fflush(stdout);			 // 立刻刷新出来
		// 如果不立刻刷新，所有的数据都会放进缓冲区里面不显示出来，达不到效果
		sleep(1);
	}
	printf("\n");
	return 0;
}