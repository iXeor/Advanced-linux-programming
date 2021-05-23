//fork函数演示:父子进程
#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    pid_t pid = -1;
    int x = 7;
    pid = fork();
    if (pid > 0)
    {
        x += 3;
        printf("\033[1;33m父进程 PID = %d\n", getpid());
        printf("父进程中fork返回值为：%d\n", pid);
        printf("x = %d\n", x);
    }
    else if (pid == 0)
    {
        x += 15;
        printf("\033[1;32m子进程 PID = %d，其父进程的PID = %d\n", getpid(), getppid());
        printf("子进程中fork返回值为：%d\nx = %d\n\033[0m", pid, x);
    }
    else
    {
        perror("fork失败\n");
        return -1;
    }
    return 0;
}
