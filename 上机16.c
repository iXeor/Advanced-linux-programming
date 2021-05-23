#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void exitPrint()
{
    printf("进程结束\n");
}

int main(int argc, char const *argv[])
{
    atexit(exitPrint);
    pid_t pid = -1;
    int stat = -1;
    if (argc < 3)
    {
        printf("请按以下形式运行该程序：%s <源文件> <目标文件>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        pid = fork();
        if (pid > 0)
        {
            waitpid(0, &stat, 0);
            printf("Copy Over\n");
        }
        else if (pid == 0)
        {
            execlp("cp", "cp", argv[1], argv[2], NULL);
        }
    }
    exit(EXIT_SUCCESS);
}
