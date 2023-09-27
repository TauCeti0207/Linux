#include <stdio.h>

int main(int argc, char *argv[])
{
        int a[5] = {4, 8, 1, 2, 7};
        int *p = NULL, *q;

        printf("%d %p\n", p, p);
        p = a; //&a[0];
        
        printf("%p %d\n", p, *p);

        q = p++;

        printf("%p %d\n",p, *p);
        printf("%p %d\n",q, *q);


        return 0;
}
