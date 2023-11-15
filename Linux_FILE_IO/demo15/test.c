// 写实例程序, 给文件描述符追加 O_APPEND
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    // 1. 打开一个已经存在的磁盘文件
    int fd = open("./mytest.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open");
        exit(0);
    }
    printf("fd: %d\n", fd);

    // 如果不想将数据写到文件头部, 可以给文件描述符追加一个O_APPEND属性
    // 通过fcntl获取文件描述符的 flag属性
    int flag = fcntl(fd, F_GETFL);
    // 给得到的flag追加 O_APPEND属性
    flag = flag | O_APPEND; // flag |= O_APPEND;
    // 重新将flag属性设置给文件描述符
    fcntl(fd, F_SETFL, flag);

    // 使用fd写文件, 添加的数据应该写到文件尾部
    const char *ppp = "((((((((((((((((((((((骚年，你要相信光！！！))))))))))))))))))))))";
    write(fd, ppp, strlen(ppp));
    close(fd);

    return 0;
}