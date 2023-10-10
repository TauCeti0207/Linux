#include <stdio.h>

int fib(int n);

int main(int argc, char *argv[])
{
        int n = 1;

        while (n <= 35) {
                printf("%d  ", fib(n));
                n++;
        }

        printf("\n");


        return 0;
}

int fib(int n) 
{
        if (n == 1 || n == 2)
                return 1;

        return fib(n-1)+fib(n-2);
}
