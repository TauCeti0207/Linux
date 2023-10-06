#include <stdio.h>
#include <string.h>

//char str[20];
char * getstring();

int main(int argc, char *argv[])
{
        char * r;
        
        r = getstring();
        printf("---%s---\n", getstring());

        //(*r)++;
        puts(r);

        return 0;
}

char * getstring() 
{
        //char str[20];//error
        //static char str[20];
        char * str = "hello";

       // strcpy(str, "hello");

        return str;
}
