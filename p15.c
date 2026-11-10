#include <stdio.h>

int main()
{
    int p, r, i, j, k, count = 0, found;

    printf("Enter the number of processes: ");
    scanf("%d", &p);

    printf("Enter the number of resources: ");
    scanf("%d", &r);

    
    int max[p][r], alloc[p][r], need[p][r];
    int avail[r], finish[p], safe[p];

    printf("Enter the MAX matrix:\n");

    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the Allocation matrix:\n");

    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the Available matrix:\n");

    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    printf("The Need matrix:\n");

    for(i = 0; i < p; i++)
    {
        finish[i] = 0;

        for(j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t", need[i][j]);
        }

        printf("\n");
    }

    while(count < p)
    {
        found = 0;

        for(i = 0; i < p; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < r; j++)
                    if(need[i][j] > avail[j])
                        break;

                if(j == r)
                {
                    for(k = 0; k < r; k++)
                        avail[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            printf("System is in unsafe state\n");
            return 0;
        }
    }

    printf("System is in safe state\n");
    printf("Safe Sequence is: ");

    for(i = 0; i < p; i++)
        printf("P%d\t", safe[i] + 1);

    printf("\n");

    return 0;
}
