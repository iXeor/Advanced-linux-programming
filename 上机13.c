//exec簇函数上机
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    char *const ar[] = {"hello", NULL};
    char *const envp[] = {"HELLO=helloWorld", "WORLD=linux", NULL};
    char *const str[] = {"ls", "-l", NULL};
    if (pid > 0)
    {
        printf("父进程：PID=%d\n", getpid());
        printf("\n\n-------");
        sleep(3);
    }
    else if (pid == 0)
    {
        execl("/bin/ls", "ls", "-l", NULL);
        execv("/bin/ls", str);
        execvpe("./hello", ar, envp);
        execle("hello", "hello", NULL, envp);
    }
    else if (pid < 0)
    {
        perror("fork错误");
    }
    return 0;
}
