#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int countsec = 1;
    while (1)
    {
        system("clear");
        printf("\033[1;32m%d\033[0m.getpid=%d\n", countsec, getpid());
        printf("\033[1;32m%d\033[0m.getppid=%d\n", countsec, getppid());
        printf("\033[1;32m%d\033[0m.getuid=%d\n", countsec, getuid());
        printf("\033[1;32m%d\033[0m.getgid=%d\n", countsec, getgid());
        sleep(1);
        countsec++;
    }
    return 0;
}
