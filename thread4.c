//pthread_detach方法演示
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

int main(int argc, char const *argv[])
{
    pthread_t id;
    pthread_detach(id);
    pthread_create(&id, NULL, thread1, NULL);
    while (1)
    {
        printf("main is running\n");
        sleep(1);
    }

    return 0;
}
