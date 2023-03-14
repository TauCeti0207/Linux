#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[], char* env[])
{
    printf("%s\n", getenv("PATH"));
    return 0;
}
