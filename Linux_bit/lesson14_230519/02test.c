#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    for (int i = 0; i < 135; ++i)
    {
        printf("%d:%s\n", i, strerror(i));
    }
    return 0;
}
