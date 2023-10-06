#include <stdio.h>

int main(int argc, char *argv[])
{
        char ch = 'A';

        char * p;

        p = &ch;

        printf("%c %c\n", ch, *p);

        return 0;
}
