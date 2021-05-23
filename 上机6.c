#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("请以以下方式执行程序：%s <文件目录>", argv[0]);
        return -1;
    }
    time_t tim, tmNow;
    time(&tim);
    struct tm *tm1;
    char *str = ctime(&tim);
    tm1 = localtime(&tmNow);
    time_t ti = mktime(tm1);
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
        printf("文件名：\033[1;34m%s    \t\033[0m", dirent->d_name);
        switch (dirent->d_type)
        {
        default:
            printf("未知文件\n");
            break;
        case DT_REG:
            printf("普通文件\n");
            break;
        case DT_DIR:
            printf("目录文件\n");
            break;
        case DT_FIFO:
            printf("管道文件\n");
            break;
        case DT_BLK:
            printf("块设备文件\n");
            break;
        case DT_CHR:
            printf("字符设备文件\n");
            break;
        case DT_LNK:
            printf("链接文件\n");
            break;
        case DT_SOCK:
            printf("套接字文件\n");
            break;
        }
    };
    printf("总文件数为%d个\n程序运行时间：\033[1;33m%s\033[0m", count, str);
    printf("UNIX时间戳为：%ld\n", ti);
    return 0;
}
