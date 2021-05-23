#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
void timeConv(struct timespec stampTime, char *time)
{
    struct tm tm;
    long int tick = (long int)stampTime.tv_sec;
    tm = *localtime(&tick);
    strftime(time, 96, "%Y-%m-%d (%a) %H:%M:%S %Z", &tm);
}
void typeCheck(int type, char *chkres)
{
    switch (type)
    {
    case S_IFDIR:
        strcpy(chkres, "d");
        break;
    case S_IFBLK:
        strcpy(chkres, "b");
        break;
    case S_IFIFO:
        strcpy(chkres, "p");
        break;
    case S_IFREG:
        strcpy(chkres, "-");
        break;
    case S_IFCHR:
        strcpy(chkres, "c");
        break;
    case S_IFLNK:
        strcpy(chkres, "l");
        break;
    case S_IFSOCK:
        strcpy(chkres, "s");
        break;
    default:
        strcpy(chkres, "?");
        break;
    }
}
void PerCheck(int Per, char *pres)
{
    switch (Per)
    {
    case 07:
        strcat(pres, "rwx");
        break;
    case 06:
        strcat(pres, "rw-");
        break;
    case 05:
        strcat(pres, "r-x");
        break;
    case 04:
        strcat(pres, "r--");
        break;
    case 03:
        strcat(pres, "-wx");
        break;
    case 02:
        strcat(pres, "-w-");
        break;
    case 01:
        strcat(pres, "--x");
        break;
    default:
        strcat(pres, "---");
        break;
    }
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("请输入正确的命令，形如:\n %s <file>\n", argv[0]);
        return -1;
    }
    int result = access(argv[1], F_OK);
    if (result < 0)
    {
        perror("抓取文件信息失败");
        return -1;
    }
    struct stat buffer;
    char *info = (char *)malloc(sizeof(char) * 12);
    char *time = (char *)malloc(sizeof(char) * 24);
    stat(argv[1], &buffer);
    int fileKind = (buffer.st_mode & S_IFMT);
    int userPer = (buffer.st_mode & S_IRWXU) >> 6;
    int groupPer = (buffer.st_mode & S_IRWXG) >> 3;
    int otherPer = buffer.st_mode & S_IRWXO;
    timeConv(buffer.st_mtim, time);
    typeCheck(fileKind, info);
    PerCheck(userPer, info);
    PerCheck(groupPer, info);
    PerCheck(otherPer, info);
    printf("--------------------------------------------------------------\n");
    printf("\033[1;36m文件信息: %s\n文件大小: %ld 字节\n文件类型与权限: %s\n文件最后修改时间: %s\n\033[0m", argv[1], buffer.st_size, info, time);
    printf("--------------------------------------------------------------\n");
}