//文件的基本操作：打开、读写、关闭
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int fd = -1;                                          //打开1.txt的flag
    int ret = -1;                                         //读取1.txt的flag
    int rfd = -1;                                         //读取2.txt的flag
    int wret = -1;                                        //写入1.txt的flag
    char *readbuff = (char *)malloc(sizeof(char) * 4096); //1.txt缓冲区
    char *str = (char *)malloc(sizeof(char) * 4096);      //2.txt缓冲区
    //打开文件（读写权限）
    fd = open("3.txt", O_RDWR | O_TRUNC);
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
#if 1
    //写入文件
    rfd = read(open("2.txt", O_RDONLY), str, 40960); //2.txt只读权限读取
    wret = write(fd, str, rfd);
    close(fd);
    read(open("3.txt", O_RDONLY), readbuff, 40960);
    if (wret < 0)
    {
        printf("文件写入失败\n");
    }
    else
    {
        printf("文件写入成功！写入的内容是：\n%s\n--------\n", str);
    }
#endif
//读取文件
#if 1
    lseek(fd, 0, SEEK_SET);
    ret = read(fd, readbuff, 40960);
    if (ret < 0)
    {
        printf("文件读取失败！\n");
    }
    else
    {
        printf("文件读取成功！读取了%d个字节，内容是：\n\033[1;35m%s\n\033[0m--------\n", ret, readbuff);
    }
#endif
    //关闭文件
    close(fd);
    return 0;
}