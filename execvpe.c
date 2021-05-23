//exec簇函数演示
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    char *const ar[] = {"hello", NULL};
    char *const envp[] = {"HELLO=hello", "WORLD=linux", NULL};
    if (pid > 0)
    {
        printf("父进程：PID=%d\n", getpid());
        printf("\n\n-------\n");
        sleep(3);
    }
    else if (pid == 0)
    {
        execvpe("./hello", ar, envp);
    }
    else if (pid < 0)
    {
        perror("fork错误");
    }
    return 0;
}