//信号发送端
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    kill(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
