//實現文件拷貝指令cp的功能
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("使用方法：%s 被拷贝文件的文件名 拷贝后的目标文件名\n", argv[0]);
        return -1;
    }
    int fdSource = -1, fdCopy = -1;
    int return_Source = -1, return_Copy = -1;
    fdSource = open(argv[1], O_RDONLY);                       //打開需要拷貝的文件流
    fdCopy = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0777); //打開拷貝目標文件流，沒有文件就創造文件
    char *readbuff = (char *)malloc(sizeof(char) * 4096);     //讀取緩衝區初始化
    if (fdSource < 0)
    {
        perror("文件打開失敗！\n");
        return -1;
    }
    else
    {
        printf("文件打開成功！\n");
    }
    printf("fdSource=%d \n", fdSource);
    int rBuffSize = lseek(fdSource, 0, SEEK_END);
    lseek(fdSource, 0, SEEK_SET);
    return_Source = read(fdSource, readbuff, rBuffSize);
    if (return_Source < 0)
    {
        printf("源文件讀取失敗！\n");
    }
    else
    {
        printf("源文件打開成功,文件大小爲：%d字節\n", return_Source);
    }
    write(fdCopy, readbuff, return_Source);
    return_Copy = lseek(fdCopy, 0L, SEEK_END);
    lseek(fdCopy, 0, SEEK_SET);
    if (return_Copy < 0)
    {
        printf("目標文件複製失败\n");
    }
    else
    {
        printf("目標文件複製成功！寫入大小爲：%d字節\n内容是：\n%s\n--------\n", return_Copy, readbuff);
    }
    close(fdSource);
    close(fdCopy);
}