//atexit注册进程终止处理函数
#include <stdlib.h>
#include <stdio.h>

void bye()
{
    printf("- 拜拜了您呐~\n");
}

void func()
{
    printf("- 哟，咋又来了？\n");
}
int main()
{
    int i = atexit(bye);
    int j = atexit(func);
    if (i != 0 || j != 0)
    {
        perror("设置退出方法失败!\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
