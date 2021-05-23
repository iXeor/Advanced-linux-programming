#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void fun1()
{
    printf("呦呦呦，这不毛哥吗？几天不见这么拉了~\n");
    sleep(3);
    system("clear");
}
void fun2()
{
    printf("\033[1;32m鬼！\033[0m\n\a");
    sleep(1);
    system("clear");
    system("screenfetch");
}
int main(int argc, char const *argv[])
{
    atexit(fun2);
    atexit(fun1);
    int i = 5;
    while (i)
    {
        system("clear");
        printf("\033[1;33m%d\033[0m秒后结束该进程\n", i);
        sleep(1);
        i--;
    }
    system("clear");
    exit(EXIT_SUCCESS);
    return 0;
}
