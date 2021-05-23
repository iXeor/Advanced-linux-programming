//目录读取演示
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("请输入正确的命令，形如:\n %s <dir>\n", argv[0]);
        return -1;
    }
    int count = 0;
    DIR *dp = NULL;
    struct dirent *dirent = NULL;
    dp = opendir(argv[1]);
    while (1)
    {
        dirent = readdir(dp);
        if (dirent == NULL)
        {
            closedir(dp);
            break;
        }
        count++;
        printf("文件名：%s    \t", dirent->d_name);
        switch (dirent->d_type)
        {
        default:
            printf("是未知文件\n");
            break;
        case DT_REG:
            printf("是普通文件\n");
            break;
        case DT_DIR:
            printf("是目录文件\n");
            break;
        case DT_FIFO:
            printf("是管道文件\n");
            break;
        case DT_BLK:
            printf("是块设备文件\n");
            break;
        case DT_CHR:
            printf("是字符设备文件\n");
            break;
        case DT_LNK:
            printf("是链接文件\n");
            break;
        case DT_SOCK:
            printf("是套接字文件\n");
            break;
        }
    };
    printf("总文件数为：%d个\n", count);
    return 0;
}
