#include <stdio.h>

struct process
{
    int pid, bt, wt, tat;
};

int main()
{
    int n, i, twt = 0, ttat = 0;
    float awt, atat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);
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

    awt = twt / n;
    atat = ttat / n;

    printf("\nTotal Waiting Time = %d\n", twt);
    printf("Average Waiting Time = %.2f\n", awt);
    printf("Total Turn Around Time = %d\n", ttat);
    printf("Average Turn Around Time = %.2f\n", atat);

    return 0;
}
