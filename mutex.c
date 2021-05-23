//mutex方法演示
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int num[20];
pthread_mutex_t mutex;
void *thread1(void *p)
{
    pthread_mutex_lock(&mutex);
    while (1)
    {
        for (int i = 0; i < 20; i++)
            num[i] = i + 1;
        sleep(1);
        for (int i = 0; i < 20; i++)
            printf("%d\t", num[i]);
        printf("\n");
        pthread_mutex_unlock(&mutex);
    }
}

void *thread2(void *p)
{
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < 20; i++)
            num[i] = 1;
    }
}

int main(int argc, char const *argv[])
{
    pthread_t id, id2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&id, NULL, thread1, NULL);
    pthread_create(&id2, NULL, thread2, NULL);
    pthread_join(id, NULL);
    pthread_join(id2, NULL);

    return 0;
}