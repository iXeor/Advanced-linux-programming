#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("使用方法：%s 文件名\n", argv[0]);
        return -1;
    }
    char *str1 = "ab";
    char *str2 = "cd";
    int fd1 = -1, fd2 = -1;
    int ret = -1;
    int wret1 = -1, wret2 = -1;
    char *readbuff = (char *)malloc(sizeof(char) * 4096);
    //打开文件（读写权限）
    fd1 = open(argv[1], O_RDWR | O_TRUNC);
    fd2 = open(argv[1], O_RDWR | O_TRUNC);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("文件打开失败！\n");
        return -1;
    }
    else
    {
        printf("文件打开成功！\n");
    }
    printf(" fd1=%d,fd2=%d \n", fd1, fd2);
    printf("文本长度：%d字节\n", ret);
#if 0
    while (1)
    {
        wret1 = write(fd1, str1, 2);
        wret2 = write(fd2, str2, 2);
        if (wret1 < 0)
        {
            printf("fd1文件写入失败\n");
        }
        else
        {
            printf("fd1文件写入成功！写入的内容是：\n%s\n--------\n", str1);
        }
        sleep(1);
        if (wret2 < 0)
        {
            printf("fd2文件写入失败\n");
        }
        else
        {
            printf("fd2文件写入成功！写入的内容是：\n%s\n--------\n", str2);
        }
    }
#endif
//读取文件
#if 1
    while (1)
    {
        ret = read(fd1, readbuff, 10);
        if (ret < 0)
        {
            printf("fd1文件读取失败！\n");
        }
        else
        {
            printf("fd1文件读取成功！读取了%d个字节，内容是：\n\033[1;35m%s\n\033[0m--------\n", ret, readbuff);
        }
        sleep(1.0);
        ret = read(fd2, readbuff, 10);
        if (ret < 0)
        {
            printf("fd2文件读取失败！\n");
        }
        else
        {
            printf("fd2文件读取成功！读取了%d个字节，内容是：\n\033[1;35m%s\n\033[0m--------\n", ret, readbuff);
        }
    }
#endif
    //关闭文件
    close(fd1);
    close(fd2);
    return 0;
}