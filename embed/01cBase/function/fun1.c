#include <stdio.h>

double power(double, int);

int main() 
{
        double x = 2, ret;
        int n = 3;

        ret = power(x, n);

        printf("%lf %d = %lf\n", x, n, ret);

        return 0;
}

double power(double x, int n) 
{
        double r = 1;
        int i;

        for (i = 1; i <= n; i++)
                r *= x;

        return r;
}
