#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
        char ch1[] = "hello World!";
        char ch2[] = "hello World!";

        char * p;

        p = ch1;
        //ch1[0]---*(ch1+0)----p[0], *p
        if(isalpha(*p)) {
                if (isupper(*p)) 
                        *p = tolower(*p);
                else
                        *p = toupper(*p);
        }
        printf("%p %s\n", p, p);

        p = ch2;
        printf("%p %s\n",p, p);

        return 0;
}
