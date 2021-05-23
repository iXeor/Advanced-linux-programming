//pthread_cancel方法演示
#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

pthread_t id;

void sig_handler(int sig)
{
    pthread_cancel(id);
}

void *thread1(void *p)
{
    while (1)
    {
        printf("thread1 is running!\n");
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    alarm(5);
    signal(SIGALRM, sig_handler);
    pthread_create(&id, NULL, thread1, NULL);
    pthread_join(id, NULL);
    return 0;
}
