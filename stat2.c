//stat应用，获取文件类型
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
    struct stat buffer;
    int result = stat(argv[1], &buffer);
    if (result < 0)
    {
        perror("获取文件信息失败\n");
        return -1;
    }
    printf("File Kind:\t");
    if (S_ISREG(buffer.st_mode))
    {
        printf("Normal\n");
    }
    else if (S_ISDIR(buffer.st_mode))
    {
        printf("Directory\n");
    }
    else
        printf("Others\n");
    return result;
}