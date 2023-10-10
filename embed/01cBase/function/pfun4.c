#include <stdio.h>

char * itoa(int n);

int main(int argc, char *argv[])
{
        int n;
        char * s;

        printf("input:");
        scanf("%d", &n);

        s = itoa(n);

        puts(s);

        return 0;
}

char * itoa(int n) 
{
        int temp, i = 0, j;
        static char p[50];

        while (n) {
                temp = n % 10;
                n /= 10;
                p[i] = temp + '0';
                i++;
        }
        p[i] = '\0';

        j = i-1;
        i = 0;

        while (i < j) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                i++;
                j--;
        }

        return p;
}
