#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int fd = -1, fd2 = -1;
    int readfile = -1;
    int wrfile = -1;
    char *buffer = (char *)malloc(sizeof(char) * 4096);
    char *buffer2 = (char *)malloc(sizeof(char) * 4096);
    char ins;
    fd = open("test1.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("文件打开失败\n");
        return -1;
    }
    else
    {
        printf("文件打开成功\n");
    }
#if 1
    readfile = read(fd, buffer, 40960);
    printf("读取了%d字节\n", readfile);
#endif

#if 1
    fd2 = open("test2.txt", O_RDWR | O_TRUNC);
    if (fd2 < 0)
    {
        perror("文件打开失败\n");
    }
    else
    {
        lseek(fd2, 20, SEEK_SET);
        wrfile = write(fd2, buffer, strlen(buffer));
        if (wrfile < 0)
        {
            perror("写入失败\n");
        }
        else
        {
            lseek(fd2, -23, SEEK_END);
            read(fd2, buffer2, 40960);
            printf("写入成功,非空洞部分文本为：%s\n", buffer2);
        }
    }

#endif
    return 0;
}