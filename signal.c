//singal函数演示
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int sig)
{
    printf("\nsig_handler sig = %d\n", sig);
    exit(EXIT_SUCCESS);
}

int main(int argc, char const *argv[])
{
    //signal(SIGKILL, SIG_IGN);
    signal(SIGINT, sig_handler);
    printf("While之前\n");
    while (1)
        ;
    return 0;
}
