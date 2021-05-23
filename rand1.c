//随机数生成演示
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    /*
    if (argc != 2)
    {
        printf("请以以下方式执行程序：%s <种子值>", argv[0]);
        return -1;
    }
    //unsigned int seed = atoi(argv[1]);
    */
    int i = 0;
    printf("RAND_MAX=%d\n", RAND_MAX);
    srand(time(NULL));
    for (i = 1; i <= 6; i++)
    {
        printf("rand[\033[1;32m%d\033[0m] = \033[1;35m %d \033[0m \n", i, rand());
    }
    for (i = 1; i <= 6; i++)
    {
        printf("Range:(0~10)\nrand[\033[1;32m%d\033[0m] = \033[1;35m %d \033[0m \n", i, rand() % 11);
    }
    return 0;
}
