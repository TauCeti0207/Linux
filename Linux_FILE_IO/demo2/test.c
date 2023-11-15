#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    // 创建新文件
    int fd = open("./new.txt", O_CREAT | O_RDWR, 0664);
    if (fd == -1)
    {
        printf("打开文件失败\n");
    }
    else
    {
        printf("创建新文件成功, fd: %d\n", fd);
    }

    close(fd);
    return 0;
}