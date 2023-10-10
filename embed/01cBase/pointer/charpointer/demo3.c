#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
        char * p1 = "hello World!";
        char * p2 = "hello World!";

        *p1 -= 32;

        printf("&p1=%p %p %s\n", &p1, p1, p1);

        printf("&p2=%p %p %s\n", &p2, p2, p2);

        return 0;
}
