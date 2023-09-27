#include <stdio.h>

int main(int argc, char *argv[])
{
        int a = 10;
        int * p;
        int * q;

        p = &a;
        //q = &a;
        q = p;

        printf("&p:%p %d\n", &p, sizeof(p));
        printf("%p %p\n", p, &a);
        printf("%d %d\n", a, *p);

        printf("\n\n&q:%p %d\n", &q, sizeof(q));
        printf("%p %d\n", q, *q);

        return 0;
}
