#include <stdio.h>

int main(int argc, char *argv[])
{
        int a[3][2] = {{1, 6}, {9, 12}, {61, 12}};
        int * p, i, n;

        n = sizeof(a) / sizeof(int);

        printf("%p %p\n", a, a+1);
        printf("%p %p\n", a[0], a[0]+1);
        printf("%p %p\n", *a, *a+1);

        return 0;
}
