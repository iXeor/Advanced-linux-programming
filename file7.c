//文件共享:不同进程使用open打开同一文件
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
    char *str1 = "**";
    char *str2 = "cd";
    int fd = -1;                                          //打开1.txt的flag
    int ret = -1;                                         //读取1.txt的flag
    int rfd = -1;                                         //读取2.txt的flag
    int wret1 = -1, wret2 = -1;                           //写入1.txt的flag
    char *readbuff = (char *)malloc(sizeof(char) * 4096); //1.txt缓冲区
    char *str = (char *)malloc(sizeof(char) * 4096);      //2.txt缓冲区
    //打开文件（读写权限）
    fd = open(argv[1], O_RDWR); //O_TRUNC | O_APPEND
    if (fd < 0)
    {
        perror("文件打开失败！\n");
        return -1;
    }
    else
    {
        printf("文件打开成功！\n");
    }
    printf(" fd=%d \n", fd);
    printf("文本长度：%d字节\n", ret);
#if 0
    while (1)
    {
        wret1 = write(fd, str1, 2);
        if (wret1 < 0)
        {
            printf("fd文件写入失败\n");
        }
        else
        {
            printf("fd文件写入成功！写入的内容是：\n%s\n--------\n", str1);
        }
        sleep(1);
    }
#endif
//读取文件
#if 1
    while (1)
    {
        //lseek(fd, 0, SEEK_SET);
        ret = read(fd, readbuff, 4);
        if (ret < 0)
        {
            printf("fd文件读取失败！\n");
        }
        else
        {
            printf("fd文件读取成功！读取了%d个字节，内容是：\n\033[1;35m%s\n\033[0m--------\n", ret, readbuff);
        }
        sleep(1.0);
    }
#endif
    //关闭文件
    close(fd);
    return 0;
}