//获取PID相关信息函数
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("getpid=%d\n", getpid());
    printf("getppid=%d\n", getppid());
    printf("getuid=%d\n", getuid());
    printf("getgid=%d\n", getgid());
    return 0;
}
