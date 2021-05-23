//SIGCHLD信号演示
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void sig_handler(int sig)
{
    printf("等待子进程结束\n");
    waitpid(0, NULL, 0);
    printf("回收完成\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid > 0)
    {
        printf("父进程正在运行 PID = %d\n", getpid());
        signal(SIGCLD, sig_handler);
        while (1)
            ;
    }
    else if (pid == 0)
    {
        printf("子进程正在运行 PID = %d\n", getpid());
    }
    else
    {
        printf("Fork Failed!\n");
    }
    return 0;
}
