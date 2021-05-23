//kill/raise函数
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_handler(int sig)
{
    printf("Hello World!\nPID = %d\nsig = %d\n", getpid(), sig);
}

int main(int argc, char const *argv[])
{
    signal(SIGINT, sig_handler);
    kill(getpid(), SIGINT);
    //raise(SIGINT);
    return 0;
}
