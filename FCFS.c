#include <stdio.h>

int main()
{
    int n, bt[20], at[20], wt[20], tat[20], ft[20];
    int avwt = 0, avtat = 0;
    int i, j;

    printf("Enter total number of processes (max 20): ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++)
    {
        printf("P[%d] Arrival Time: ", i+1);
        scanf("%d", &at[i]);

        printf("P[%d] Burst Time: ", i+1);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    ft[0] = at[0] + bt[0];
    wt[0] = 0;
    tat[0] = bt[0];

    for(i = 1; i < n; i++)
    {
        if(ft[i-1] < at[i])
            ft[i] = at[i] + bt[i];
        else
            ft[i] = ft[i-1] + bt[i];

        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avwt += wt[i];
        avtat += tat[i];
    }

    avtat += tat[0];

    printf("\nProcess\tAT\tBT\tFT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ft[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)avwt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)avtat/n);

    return 0;
}
