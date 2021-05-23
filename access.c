//access函数应用
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int result = -1;
    result = access(argv[1], F_OK);
    if (result < 0)
    {
        perror("文件不存在\n");
        return -1;
    }
    else
        printf("文件存在");
    result = access(argv[1], R_OK);
    if (result < 0)
    {
        printf("不可读");
    }
    else
    {
        printf("可读");
    }
    result = access(argv[1], W_OK);
    if (result < 0)
    {
        printf("不可写");
    }
    else
    {
        printf("可写");
    }

    result = access(argv[1], X_OK);
    if (result < 0)
    {
        printf("不可执行\n");
    }
    else
    {
        printf("可执行\n");
    }
    return 0;
}