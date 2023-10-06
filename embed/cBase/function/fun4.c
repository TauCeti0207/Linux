#include <stdio.h>

void  swap(int x, int y);

int main() 
{
        int a = 10;
        int b = 20;

        printf("before:%d %d\n", a, b);

        swap(a, b);

        printf("after:%d %d\n", a, b);

        return 0;
}
//int x = a; int y = b;
void  swap(int x, int y) 
{
        int t;
        t = x;
        x = y;
        y = t;
}
