//#include <stdio.h>
int scanf(const char *format, ...);
int printf(const char *format, ...);


double power(double, int);

int main() 
{
        double x, ret;
        int n;

        printf("input:");
        scanf("%lf%d", &x, &n);

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
