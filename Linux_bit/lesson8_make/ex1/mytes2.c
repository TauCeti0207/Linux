/*************************************************************************
        > File Name: mytes2.c
        > Author: tauceti0207
        > Mail: 2076188013@qq.com
        > Created Time: Fri Apr 28 13:21:17 2023
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
int main()
{
  int cnt = 9;
  while(cnt)
  {
    printf("%d\r", cnt--);
    fflush(stdout); // 立刻刷新出来
    // 如果不立刻刷新，所有的数据都会放进缓冲区里面不显示出来，达不到效果
    sleep(1);
  }
  return 0;
}
