//wait函数上机练习
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = -1;
    int status = -1;
    pid = fork();
    if (pid > 0)
    {
        printf("父进程 PID=%d", getpid());
        pid = wait(&status);
        printf("子进程结束，pid=%d\n", pid);
        printf("子进程是否正常终止：%d\n", WIFEXITED(status));
        printf("子进程是否被信号终止：%d\n", WIFSIGNALED(status));
        printf("子进程正常终止返回值：%d\n", WEXITSTATUS(status));
    }
    else if (pid == 0)
    {
        printf("子进程 PID = %d\n", getpid());
        printf("该进程的父进程PID = %d\n", getppid());
    }
    else
        perror("fork失败\n");
    return 0;
}