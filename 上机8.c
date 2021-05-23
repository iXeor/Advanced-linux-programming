#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        printf("rand[%d] = %d\n", i, rand() % 20 + 1);
    }
    return 0;
}
