#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
        char ch[50] = "welcome";
        char * p1 = "hello World!";
        
        //strcpy(ch, p1);
        strcpy(p1, ch);

        puts(ch);
        puts(p1);

        return 0;
}
