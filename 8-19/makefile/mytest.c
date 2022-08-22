#include <stdio.h>
#include <unistd.h>
int main()
{
  int cnt = 9;
  while(cnt)
  {
    printf("%d\r", cnt--);
    fflush(stdout); // 立刻刷新出来
    sleep(1);
  }
  //sleep(2);
  return 0;
}
