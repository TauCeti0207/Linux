#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) // char* argv[] 指针数组
{
    // argc存的是argv数组元素个数
    // argv里面放的是？
    for(int i = 0; i < argc; ++i)
    {
        printf("argv[%d]:%s\n",i,argv[i]);
    }	
    return 0;
}
