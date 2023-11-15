// 文件的拷贝
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    // 1. 打开存在的文件english.txt, 读这个文件
    int fd1 = open("./english.txt", O_RDONLY);
    if (fd1 == -1)
    {
        perror("open-readfile");
        return -1;
    }

    // 2. 打开不存在的文件, 将其创建出来, 将从english.txt读出的内容写入这个文件中
    int fd2 = open("copy.txt", O_WRONLY | O_CREAT, 0664);
    if (fd2 == -1)
    {
        perror("open-writefile");
        return -1;
    }

    // 3. 循环读文件, 循环写文件
    char buf[4096];
    int len = -1;
    while ((len = read(fd1, buf, sizeof(buf))) > 0) // read 函数返回的值是读取的字节数
    {
        // 将读到的数据写入到另一个文件中
        write(fd2, buf, len);
    }
    // 4. 关闭文件
    close(fd1);
    close(fd2);

    return 0;
}