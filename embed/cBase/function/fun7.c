#include <stdio.h>
int str_fun(char * p);

int main(int argc, char *argv[])
{
        char s[] = "welcome2017Beijing";
        int n;

        n = str_fun(s);
        printf("n=%d %s\n", n, s);

        return 0;
}

int str_fun(char * p) //char * p = s;
{
        int num = 0;
        while (*p != '\0') {//while (*p)
                if (*p <= 'z' && *p >= 'a') {
                        num++;
                        *p -= ' ';
                }
                p++;
        }
        return num;
}
