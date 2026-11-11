7. Write a C program to demonstrate Semaphores using binary semaphores.

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define N 3
    
sem_t s;

void *fun(void *arg) {
    int id = *(int *)arg;
    printf("Thread %d waiting\n", id);
    sem_wait(&s);
    printf("Thread %d entered critical section\n", id);
    sleep(2);
    printf("Thread %d exited critical section\n", id);
    sem_post(&s);
    return NULL;
}

int main() {
    pthread_t t[N];
    int id[N];
    sem_init(&s, 0, 1);
    for (int i = 0; i < N; i++) {
        id[i] = i + 1;
        pthread_create(&t[i], NULL, fun, &id[i]);
    }
    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);
    sem_destroy(&s);
    printf("All threads finished\n");
    return 0;
}
