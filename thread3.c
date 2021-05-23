//pthread_join方法演示
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread1(void *p)
{
    while (1)
    {
        printf("thread1 is running!\n");
        sleep(1);
    }
}

void *thread2(void *p)
{
    while (1)
    {
        printf("thread2 is running!\n");
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t id;
    pthread_create(&id, NULL, thread1, NULL);
    pthread_create(&id, NULL, thread2, NULL);
    printf("main is running\n");
    pthread_join(id, NULL);
    return 0;
}
