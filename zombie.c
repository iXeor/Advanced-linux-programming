//fork函数演示:僵尸进程
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char const *argv[])
{
    pid_t pid = -1;
    pid = fork();
    if (pid > 0)
    {
        printf("\033[1;33m父进程 PID = %d\n", getpid());
        printf("父进程中fork返回值为：%d\n", pid);
        while (1)
            ;
    }
    else if (pid == 0)
    {
        printf("\033[1;32m子进程 PID = %d，其父进程的PID = %d\n", getpid(), getppid());
        printf("子进程中fork返回值为：%d\n\n\033[0m", pid);
    }
    else
    {
        perror("fork失败\n");
        return -1;
    }
    return 0;
}