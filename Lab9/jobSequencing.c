#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct job{
    int jNo;
    int deadline;
    int profit;
}job;

void sort(job *arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j].profit <  arr[j+1].profit)
            {
                job temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int maxDeadline;
    int n; 
    printf("Enter the max deadline: ");
    scanf("%d", &maxDeadline);
    int chart[maxDeadline];
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    job arr[n];
    for(int i = 0; i < n; i++)
    {   
        printf("Enter the details of jobs %d:\n", i+1);
        arr[i].jNo = i+1;
        printf("Deadline: ");
        scanf("%d", &arr[i].deadline);
        printf("Profit: ");
        scanf("%d", &arr[i].profit);
    }

    sort(arr, n);
    memset(chart, -1, sizeof(chart));

    int k, profit = 0;
    for(int i = 0; i < n; i++)
    {
        k = arr[i].deadline - 1;
        while(chart[k] != -1)
            k--;
        if(k >= 0)
        {
            chart[k] = arr[i].jNo;
            profit += arr[i].profit;
        }
    }
    for(int i = 0; i < maxDeadline-1; i++)
    {
        printf("J%d->", chart[i]);
    }
    printf("J%d\n", chart[maxDeadline-1]);
    printf("Profit earned = %d\n", profit);
    return 0;
}