#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
void fun()
{

}

int main()
{
    printf("hello fun");
    sleep(1);
    _exit(111);
    return 10;
}
