///First Come First Serve
//With Arrival time = 0
#include <stdio.h>
/*
void findWaitTime(int n, int b[], int w[])
{
    w[0] = 0;
    for (int i = 1; i < n; i++)
    {
        w[i] = b[i - 1] + w[i - 1];
    }
}

void findTat(int n, int b[], int w[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = b[i] + w[i];
    }
}

void findAvgTime(int n, int b[])
{
    int i, w[n], tat[n];
    int avgWt, avgTat;
    findWaitTime(n, b, w);
    findTat(n, b, w, tat);
    int sumWt = 0, sumTat = 0;
    for (i = 0; i < n; i++)
    {
        sumWt = sumWt + w[i];
        sumTat = sumTat + tat[i];

        printf(" p[%d]\t%d\t%d\t%d\n", i, b[i], w[i], tat[i]);
    }

    avgWt = (float)sumWt / (float)n;
    avgTat = (float)sumTat / (float)n;
    printf("\nAvg Waiting time is : %d \n", avgWt);
    printf("Avg Turn Around time is : %d \n", avgTat);
}

int main()
{

    int n, i;
    printf("Enter No. of processes : ");
    scanf("%d", &n);
    int b[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst time for p[ %d ] :", i);
        scanf("%d", &b[i]);
    }

    findAvgTime(n, b);
    return 0;
}
*/

//With Arrival time != 0

void findWaitTime(int n, int a[], int b[], int w[])
{
    w[0] = 0;
    int i, j;
    for (i = 1; i < n; i++)
    {
        int sum = 0;
        for (j = 0; j < i; j++)
        {
            sum = sum + b[j];
        }
        w[i] = sum - a[i];
        if(w[i] < 0){
            w[i]=0;
        }
    }
}

void findTatTime(int n, int a[], int b[], int w[], int Tat[])
{
    for (int i = 0; i < n; i++)
    {
        Tat[i] = b[i] + w[i];
    }
}
void findAvgTime(int n, int a[], int b[])
{

    int w[n], tat[n] ,i;
    float avgWt , avgTat;
    findWaitTime(n, a, b, w);
    findTatTime(n, a, b, w, tat);
    int sumWt = 0, sumTat = 0;
    for (i = 0; i < n; i++)
    {
        sumWt = sumWt + w[i];
        sumTat = sumTat + tat[i];

        printf(" p[%d]\t%d\t%d\t%d\n", i, b[i], w[i], tat[i]);
    }

    avgWt = (float)sumWt / (float)n;
    avgTat = (float)sumTat / (float)n;
    printf("\nAvg Waiting time is : %f \n", avgWt);
    printf("Avg Turn Around time is : %f \n", avgTat);

}
int main()
{

    int n, i;
    printf("Enter No. of processes : ");
    scanf("%d", &n);
    int b[n], a[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival time and Burst time for p[%d] :" , i);
        scanf("%d %d", &a[i], &b[i]);
    }

    findAvgTime(n, a, b);
    return 0;
}
