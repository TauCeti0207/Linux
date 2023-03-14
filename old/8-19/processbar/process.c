#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NUM 101
#define STYLE '='

void process()
{
  char bar[NUM];
  memset(bar, '\0', sizeof(bar));
  const char* label = "|/-\\"; // \\才表示一个反斜杠
  int cnt = 0;
  while(cnt <= 100) // 打印101次
  {
    printf("loading: %-100s[%d%%] %c\r", bar, cnt, label[cnt%4]); // %4避免label越界
    fflush(stdout);
    bar[cnt++] = STYLE;
    usleep(80000);
  }
  printf("\n");
}

int main()
{
  process();
  return 0;
}
