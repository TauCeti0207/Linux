/*
 * @Author: yzq
 * @Date: 2024-07-30 18:28:00
 * @Last Modified by: yzq
 * @Last Modified time: 2024年7月30日20:42:40
 */

#include <stdio.h>
int AddToTop(int top)
{
  int res = 0;
  int i;
  for (i = 1; i <= top; ++i)
  {
    res += i;
  }
  return res;
}
int main()
{
  int result = 0;
  int top = 100;
  result = AddToTop(top);
  printf("result: %d\n", result);
  return 0;
}
