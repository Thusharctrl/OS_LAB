#include <stdio.h>

struct process
{
    int pid, bt, wt, tat;
};

int main()
{
    int n, i, tq, time = 0, flag = 0;
    int twt = 0, ttat = 0;
    float awt, atat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if(n <= 0)
        return 1;

    struct process p[n];
    int remBT[n];

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter burst time for p%d: ", i + 1);
        scanf("%d", &p[i].bt);

        remBT[i] = p[i].bt;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

   

    while(flag == 0)
    {
        flag = 1;

        for(i = 0; i < n; i++)
        {
            if(remBT[i] > 0)
            {
                flag = 0;

                if(remBT[i] > tq)
                {
                    time += tq;
                    remBT[i] -= tq;
                }
                else
                {
                    time += remBT[i];
                    remBT[i] = 0;

                    p[i].tat = time;
                    p[i].wt = time - p[i].bt;
                }
            }
        }
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

    printf("\nTotal Waiting Time: %d ms\n", twt);
    printf("Average Waiting Time: %.2f ms\n", awt);
    printf("Total Turn Around Time: %d ms\n", ttat);
    printf("Average Turn Around Time: %.2f ms\n", atat);

    return 0;
}
