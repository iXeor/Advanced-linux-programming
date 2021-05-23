//fork函数演示
#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    pid_t pid = -1;

    printf("fork\n");
    pid = fork();
    printf("After = %d\n", pid);
    return 0;
}
