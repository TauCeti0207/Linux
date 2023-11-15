#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    // 1. 定义结构体, 存储文件信息
    struct stat myst;
    // 2. 获取文件属性 english.txt
    int ret = stat("./english.txt", &myst);
    if (ret == -1)
    {
        perror("stat");
        return -1;
    }

    printf("文件大小: %d\n", (int)myst.st_size);

    // 判断文件类型
    if (S_ISREG(myst.st_mode))
    {
        printf("这个文件是一个普通文件...\n");
    }

    if (S_ISDIR(myst.st_mode))
    {
        printf("这个文件是一个目录...\n");
    }
    if (S_ISLNK(myst.st_mode))
    {
        printf("这个文件是一个软连接文件...\n");
    }

    return 0;
}