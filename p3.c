#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i, pid;

    printf("Parent process ID = %d\n", getpid());

    for(i = 1; i <= 5; i++)
    {
        pid = fork();

        if(pid == 0)
        {
            printf("Child %d with ID %d and parent process ID %d\n",
                   i, getpid(), getppid());

            exit(0);
        }
        else if(pid > 0)
        {
            wait(NULL);

            printf("Parent created child %d with PID %d\n", i, pid);
        }
        else
        {
            printf("Fork failed\n");
            return 1;
        }
    }

    return 0;
}
