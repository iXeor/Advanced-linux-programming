//fork函数演示:父子进程共享文件操作,子进程继承父进程打开的文件
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
        printf("\033[1;33m父进程 PID = %d\n", getpid());
        printf("父进程中fork返回值为：%d\n", pid);
        while (1)
        {
            int wret1 = write(fd, str1, 2);
            if (wret1 < 0)
            {
                printf("\033[1;33m文件写入失败\n");
            }
            else
            {
                printf("\033[1;33m文件写入成功！写入的内容是：\n%s\n--------\n", str1);
            }
            sleep(1);
        }
    }
    else if (pid == 0)
    {

        printf("\033[1;32m子进程 PID = %d，其父进程的PID = %d\n", getpid(), getppid());
        printf("子进程中fork返回值为：%d\n\033[0m", pid);
        while (1)
        {
            int wret1 = write(fd, str2, 2);
            if (wret1 < 0)
            {
                printf("\033[1;32m文件写入失败\n");
            }
            else
            {
                printf("\033[1;32m文件写入成功！写入的内容是：\n%s\n--------\n", str2);
            }
            sleep(1);
        }
    }
    else
    {
        perror("fork失败\n");
        return -1;
    }
    close(fd);
    return 0;
}
