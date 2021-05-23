//stat应用，获取文件信息（属性）
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    struct stat buffer;
    int result = stat("1.txt", &buffer);
    if (result < 0)
    {
        perror("获取文件信息失败\n");
        return -1;
    }
    else
    {
        printf("获取文件信息成功\n");
        printf("st_nlink=%ld\t", buffer.st_nlink);
        printf("st_mtime=%ld\t", buffer.st_mtime);
        printf("st_size=%ld\t", buffer.st_size);
    }
    return result;
}