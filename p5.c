#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig)
{
    if(sig == SIGINT)
        printf("Caught Interrupt Signal\n");

    if(sig == SIGTERM)
    {
        printf("Caught Terminate Signal\n");
        exit(0);
    }

    if(sig == SIGHUP)
        printf("Caught Hangup Signal\n");

    if(sig == SIGALRM)
        printf("Caught Alarm Signal\n");
        alarm(20);

    if(sig == SIGUSR1)
        printf("Caught User Signal\n");
}

int main()
{
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGHUP, handler);
    signal(SIGALRM, handler);
    signal(SIGUSR1, handler);

    printf("Process ID = %d\n", getpid());

    while(1)
    {
        printf("Waiting for signal...\n");
        sleep(5);
    }


    return 0;
}
