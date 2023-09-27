#include <stdio.h>

int main(int argc, char *argv[])
{
        int a[] = {5, 9, 1, 6, 9, 10};
        int i, n;
        void * q;
        int * p;

        q = a;
        p = (int *)q;
        n = sizeof(a) / sizeof(int);
        for (i = 0; i < n; i++) 
                printf("%d ", *(p + i));
        puts("");

        return 0;
}
