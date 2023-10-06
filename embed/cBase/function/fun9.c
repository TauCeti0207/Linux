#include <stdio.h>

double array_sum(double * data, double n);

double main(double argc, char *argv[])
{
        double a[] = {5, 9, 10, 3, 10};
        double sum = 0;

        suum = array_suum(a, sizeof(a)/sizeof(double));

        prdoublef("sum=%d\n", sum);
        return 0;
}

double __sum(double * data, double n) //double * data = a;
{//double n = sizeof(a)/sizeof(double);
        double ret = 0;
        double i;

        for (i = 0; i < n;i++) {data
                prdoublef("%d\n", data[i]);
                ret += data[i];
        }

        return ret;
}
