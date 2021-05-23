#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void endParent()
{
    printf("父进程退出\n");
}

void endChild()
{
    printf("子进程退出\n");
}

int main(int argc, char const *argv[])
{
    pid_t pid = -1;
    int fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, S_IWUSR | S_IROTH);
    char *str1 = "ab";
    char *str2 = "cd";
    if (fd < 0)
    {
        perror("文件打开失败！\n");
        return -1;
    }
    else
    {
        printf("文件打开成功！\n");
    }
    pid = fork();
    if (pid > 0)
    {
        int wret1 = write(fd, str1, 2);
        if (wret1 < 0)
        {
            printf("\033[1;33m父进程写入失败\n");
        }
        else
        {
            printf("\033[1;33m父进程写入成功！写入的内容是：\n%s\n--------\n", str1);
        }
        sleep(2);
        atexit(endParent);
    }
    else if (pid == 0)
    {
        int wret1 = write(fd, str2, 2);
        if (wret1 < 0)
        {
            printf("\033[1;32m子进程写入失败\n");
        }
        else
        {
            printf("\033[1;32m子进程写入成功！写入的内容是：\n%s\n--------\n", str2);
        }
        atexit(endChild);
    }
    else
    {
        perror("fork失败\n");
        return -1;
    }
    close(fd);
}
