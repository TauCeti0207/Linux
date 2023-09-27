#include <stdio.h>

int main(int argc, char *argv[])
{
         int m = 10;
         const int * p;
         int * const q = &m;
         const int * const r = &m;
         
         p = &m;//right;

         //(*p)++; error;

         //q = &m; error;
         *q = 20;//right

         r++;
         (*r)++

        return 0;
}
