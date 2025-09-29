/*
 * @Author: yzq
 * @Date: 2024-07-30 23:19:18
 * @Last Modified by: yzq
 * @Last Modified time: 2024-07-30 23:50:18
 */

#include <stdio.h>
#include <unistd.h>
int main()
{
  printf("hello Linux");
  fflush(stdout); // 立刻刷新出来
  // sleep(2);
  return 0;
}
