#include <stdio.h>
#include <string.h>

char * getstring();

int main(int argc, char *argv[])
{
        char * r;
        
        r = getstring();
        printf("---%s---\n", getstring());

        (*r)++;
        puts(r);

        return 0;
}

char * getstring() 
{
        char str[20];

        strcpy(str, "hello");

        return str;
}
