#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *process(void *arg)
{
    int id = *(int *)arg, i;

    for(i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&lock);

        count++;
        printf("Process %d: Counter = %d\n", id, count);

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int a = 1, b = 2;

    pthread_create(&t1, NULL, process, &a);
    pthread_create(&t2, NULL, process, &b);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter = %d\n", count);

    return 0;
}
