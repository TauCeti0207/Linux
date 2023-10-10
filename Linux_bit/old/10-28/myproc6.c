#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <string.h>

int main()
{
    for(int i = 0; i < 100; ++i)
    {
        printf("%d:%s\n",i,strerror(i));
    }
    return 0;
}
