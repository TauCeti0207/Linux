#include <stdio.h>

double power(double, int);

int main() 
{
        double x = 2;
        int n = 3;
        double ret;

        printf("&x=%p &n=%p\n", &x, &n);

        ret = power(x, n);

        printf("%lf %d = %lf\n", x, n, ret);

        return 0;
}

double power(double a, int b) //double a = x; int b = n;
{
        double r = 1;
        int i;

        printf("&a=%p &b=%p\n", &a, &b);

        for (i = 1; i <= b; i++)
                r *= a;

        return r;
}
