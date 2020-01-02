//Shortest Job First with any arrival time 
//NON-PREMPTIVE

#include <stdio.h>

void Sort(int n, int a[], int b[])
{

    int i, j,temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (b[i] > b[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }

            if (b[i] == b[j])
            {
                if (a[i] > a[j])
                {   temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;

                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
            }
        }
    }
}

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
        if(w[i]<0){
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

    int w[n], tat[n], i;
    float avgWt, avgTat;
    Sort(n,a,b);
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
        printf("Enter Arrival time and Burst time for p[%d] :", i);
        scanf("%d %d", &a[i], &b[i]);
    }

    findAvgTime(n, a, b);
    return 0;
}
