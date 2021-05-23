//alarm函数演示
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig)
{
    exit(EXIT_SUCCESS);
}

void mysleep(int sec)
{
    alarm(sec);
    signal(SIGALRM, sig_handler);
    pause();
}

int main(int argc, char const *argv[])
{
    int x = atoi(argv[1]);
    printf("Sleep %d sec.\n", x);
    mysleep(x);
    exit(0);
}
