#include <stdio.h>

int main(int argc, char *argv[])
{
        int a[] = {1, 6, 9, 12, 61, 12, 21};
        int *p, i, n;
        
        p = a;
        n = sizeof(a) / sizeof(int);

        printf("%p %p %p\n", a, a+1, a+2);

        for (i = 0; i < n; i++)
                printf("%d %d %d %d\n", a[i], *(p+i), *(a+i), p[i]);
        puts("");

        p++;

        printf("%d\n", p[1]);//*(p+1)

        return 0;
}
