#include <stdio.h>
#include <math.h>

#define N 1
#define _DEBUG_

int main(int argc, char *argv[])
{
        int m = 624;

        m += 1;

#ifdef _DEBUG_
        printf("%s %s, %d\n", __FILE__, __FUNCTION__, __LINE__);
#endif

        m = sqrt(m);

        printf("m=%d\n", m);

        return 0;
}
