#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count = 0;
sem_t s;

void *process(void *arg)
{
    int id = *(int *)arg, i;

    for(i = 0; i < 5; i++)
    {
        sem_wait(&s);

        count++;
        printf("Process %d: Counter = %d\n", id, count);

        sem_post(&s);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int a = 1, b = 2;

    sem_init(&s, 0, 1);

    pthread_create(&t1, NULL, process, &a);
    pthread_create(&t2, NULL, process, &b);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter = %d\n", count);

    sem_destroy(&s);

    return 0;
}
