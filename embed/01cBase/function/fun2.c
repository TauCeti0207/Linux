#include <stdio.h>

double x = 2;
int n = 3;

double power();

int main() 
{
//        double x = 2;
//        int n = 3;
        double ret;

        ret = power();

        printf("%lf %d = %lf\n", x, n, ret);

        return 0;
}

double power() 
{
        double r = 1;
        int i;

        for (i = 1; i <= n; i++)
                r *= x;

        return r;
}
