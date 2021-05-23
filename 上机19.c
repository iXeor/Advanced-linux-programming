//pthread_create方法演示--线程参数传递
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

pthread_t id, id2;

void sig_handler(int sig)
{
    pthread_cancel(id);
}

void *thread1(void *p)
{
    int *id = p;
    while (1)
    {
        printf("M\n");
        sleep(1);
    }
}

void *thread2(void *p)
{
    char *str = p;
    while (1)
    {
        printf("Y\n");
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    alarm(5);
    signal(SIGALRM, sig_handler);
    pthread_create(&id, NULL, thread1, NULL);
    pthread_create(&id2, NULL, thread2, NULL);
    pthread_join(id, NULL);
    pthread_join(id2, NULL);
    return 0;
}