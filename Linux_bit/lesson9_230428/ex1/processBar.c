#include "processBar.h"
#include <unistd.h>
#include <string.h>

void processbar(int speed)
{
	char bar[NUM];
	memset(bar, '\0', sizeof(bar));
	const char *label = "|/-\\"; // \\表示一个反斜杠
	int cnt = 0;
	int len = strlen(label);
	while (cnt <= LOOPNUM) // 打印101次
	{
		printf("loading: %-100s[%d%%] %c\r", bar, cnt, label[cnt % len]); // %4避免label越界
		//%-100s 表示左对齐的字符串，宽度为100个字符；
		// %d%% 表示显示整数 cnt 后跟一个百分号；%c 表示显示 label[cnt % 4] 字符。
		fflush(stdout);
		bar[cnt++] = STYLE;
		if (cnt <= 99)
			bar[cnt] = RIGHT;
		usleep(speed);
	}
	printf("\n"); // 跑完需换行
}