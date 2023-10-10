#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *);

int main(int argc, char *argv[])
{
        int s[] = {89, 23, 10, 8, 7, 61}, n, i;

	n = sizeof(s)/sizeof(int);
        for (i = 0; i < n; i++)
                printf("%d ", s[i]);
        qsort(s, n, sizeof(int), compare);
	puts("");
        for (i = 0; i < n; i++)
                printf("%d ", s[i]);
        puts("");

        return 0;
}
//The comparison function must return an integer less than, equal to, or greater  than zero  if the first argument is considered to be respectively less than, equal to, or greater than the second. 
int compare(const void * p, const void * q) 
{
        return (*(int *)p - *(int *)q);
}
