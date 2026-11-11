6. Write a C program to demonstrate Critical section in process synchronization.
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
    
int counter = 0;
pthread_mutex_t mutex;

void *fun(void *arg) {
    int id = *(int *)arg;
    printf("Thread %d waiting\n", id);
    pthread_mutex_lock(&mutex);
    printf("Thread %d entered critical section\n", id);
    counter++;
    printf("Counter = %d\n", counter);
    sleep(1);
    printf("Thread %d exited critical section\n", id);
    pthread_mutex_unlock(&mutex);
    return NULL;
}
int main() {
    pthread_t t[3];
    int id[3] = {1, 2, 3};
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, fun, &id[i]);
    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);
    pthread_mutex_destroy(&mutex);
    printf("Final counter = %d\n", counter);
    return 0;
}
