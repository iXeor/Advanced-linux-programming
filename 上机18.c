#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_t id, id2;
void *thread1(void *p)
{
    int *id = p;
    while (1)
    {
        char *ch = p;
        printf("%c\n", *ch);
        sleep(3);
    }
}

void *thread2(void *p)
{
    char *ch = p;
    while (1)
    {
        printf("%c\n", *ch);
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    char *mChar = "M";
    char *yChar = "Y";
    pthread_create(&id, NULL, thread1, mChar);
    pthread_create(&id2, NULL, thread2, yChar);
    pthread_join(id, NULL);
    pthread_join(id2, NULL);
    return 0;
}