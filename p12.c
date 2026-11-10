#include <stdio.h>

struct process
{
    int pid, bt, wt, tat;
};

int main()
{
    int n, i, j, min, twt = 0, ttat = 0;
    float awt, atat;

    printf("Enter no of process: ");
    scanf("%d", &n);

  

    struct process p[n], temp;

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter burst time for p%d: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    /* Sorting based on burst time */
    for(i = 0; i < n-1; i++)
    {
        min = i;

        for(j = i+1; j < n; j++)
        {
            if(p[j].bt < p[min].bt)
                min = j;
        }

        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
    }

    p[0].wt = 0;
    p[0].tat = p[0].bt;

    for(i = 1; i < n; i++)
    {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    printf("\nPID\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].bt, p[i].wt, p[i].tat);

        twt += p[i].wt;
        ttat += p[i].tat;
    }

    awt = (float)twt / n;
    atat = (float)ttat / n;

    printf("\nTotal Waiting Time = %.2f\n", (float)twt);
    printf("Total Turn Around Time = %.2f\n", (float)ttat);
    printf("Average Waiting Time = %.2f\n", awt);
    printf("Average Turn Around Time = %.2f\n", atat);

    return 0;
}
