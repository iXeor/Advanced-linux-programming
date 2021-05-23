//pthread_create方法演示--线程参数传递
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread1(void *p)
{
    int *id = p;
    while (1)
    {
        printf("thread1 is running!\tID = %d\n", *id);
        sleep(1);
    }
}

void *thread2(void *p)
{
    char *str = p;
    while (1)
    {
        printf("thread2 is running!\t%s", str);
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t id, id2;
    int idint = 1;
    char *string = "Hello World\n";
    pthread_create(&id, NULL, thread1, &idint);
    pthread_create(&id2, NULL, thread2, string);
    while (1)
    {
        printf("main is running\n");
        sleep(1);
    }

    return 0;
}