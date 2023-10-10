#include <stdio.h>

int main(int argc, char *argv[])
{
        double a;
        double * p;

        p = &a;

        printf("%d %d %p\n", sizeof(double), sizeof(p), p);

        return 0;
}
