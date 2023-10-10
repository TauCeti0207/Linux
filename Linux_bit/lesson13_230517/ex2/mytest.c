#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int un_g_val; // 未定义的全局变量
int g_val = 100;
int main(int argc, char* argv[], char* env[])
{
    static int s_n = 1;
    printf("code addr:           %p\n", main);
    printf("init global addr:    %p\n", &g_val);
    printf("uninit global addr:  %p\n", &un_g_val);
    printf("static data addr:    %p\n", &s_n);
    char* m1 = (char*)malloc(100);
    char* m2 = (char*)malloc(100);
    char* m3 = (char*)malloc(100);
    char* m4 = (char*)malloc(100);
    printf("headp addr:          %p\n", m1); // &m1 在栈上
    printf("headp addr:          %p\n", m2); // 堆区往高地址增长
    printf("headp addr:          %p\n", m3); 
    printf("headp addr:          %p\n", m4);
    printf("stack addr:          %p\n", &m1); // 栈区往低地址增长
    printf("stack addr:          %p\n", &m2);
    printf("stack addr:          %p\n", &m3);
    printf("stack addr:          %p\n", &m4);
    for(int i = 0; i < argc; i++)
    {
        printf("argv addr:       %p\n", argv[i]); // 命令行参数地址
    }
    for(int i = 0; env[i]; ++i)
    {
        printf("env addr:        %p\n", env[i]);
    }
    return 0;
}
