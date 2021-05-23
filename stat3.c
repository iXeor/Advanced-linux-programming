//stat应用，获取文件类型
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
void stamp_to_standard(struct timespec stampTime, char *time)
{
    long int tick = (long int)stampTime.tv_sec;
    struct tm tm;
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
        printf("Please RUN the program as this form:\n %s <file>\n", argv[0]);
        return -1;
    }
    int result = access(argv[1], F_OK);
    if (result < 0)
    {
        perror("Failed to get file");
        return -1;
    }
    struct stat buffer;
    char *info = (char *)malloc(sizeof(char) * 24);
    char *time = (char *)malloc(sizeof(char) * 24);
    stat(argv[1], &buffer);
    int fileKind = (buffer.st_mode & S_IFMT);
    int userPer = (buffer.st_mode & S_IRWXU) >> 6;
    int groupPer = (buffer.st_mode & S_IRWXG) >> 3;
    int otherPer = buffer.st_mode & S_IRWXO;
    stamp_to_standard(buffer.st_mtim, time);
    typeCheck(fileKind, info);
    PerCheck(userPer, info);
    PerCheck(groupPer, info);
    PerCheck(otherPer, info);
    printf("\033[1;34m▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
    printf("\033[0mFile: %s\nFile Size: %ld Byte\nFile Type & Permission: %s\nTime of last modification: %s\n", argv[1], buffer.st_size, info, time);
    printf("\033[1;34m▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\033[0m\n");
    free(info);
    free(time);
}