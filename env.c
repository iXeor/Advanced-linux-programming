//环境变量演示
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    extern char **environ;
    int i = 0;
#if 0
    while (environ[i] != NULL)
    {
        printf("env[%d]=%s\n", i, environ[i]);
        i++;
    }
#endif
    printf("HOME=%s\n", getenv("HOME"));
    printf("PWD=%s\n", getenv("PWD"));
    printf("USER=%s\n", getenv("USER"));
    return 0;
}
