//waitpid练习
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
        printf("该进程为父进程 PID = %d\n", getpid());
        waitpid(0, &status, 0); //等待同组进程结束
                                //waitpid(-1,&status,0);//等待任何进程结束
                                //waitpid(pid,&status,0);//等待指定进程结束
                                //waitpid(pid,&status,WNOHANG);//非阻滞状态等待
        printf("子进程结束，pid=%d\n", pid);
        printf("子进程是否正常终止：%d\n", WIFEXITED(status));
        printf("子进程是否被信号终止：%d\n", WIFSIGNALED(status));
        printf("子进程正常终止返回值：%d\n", WEXITSTATUS(status));
    }
    else if (pid == 0)
    {
        printf("该进程为子进程 PID = %d\n", getpid());
        printf("该进程的父进程 PID = %d\n", getppid());
    }
    else
        perror("fork失败\n");
    return 0;
}
