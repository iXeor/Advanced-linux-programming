//exec簇函数演示
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    char *const str[] = {"ls", "-l", NULL};
    if (pid > 0)
    {
        printf("父进程：PID=%d\n", getpid());
        sleep(3);
    }
    else if (pid == 0)
    {
        execvp("ls", str);
    }
    else if (pid < 0)
    {
        perror("fork错误");
    }
    return 0;
}