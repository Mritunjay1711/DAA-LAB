#include<stdio.h>
#include<stdlib.h>

typedef struct item{
    int profit;
    int weight;
}item;

void sort(item *arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(((double)arr[j].profit/arr[j].weight) < ((double)arr[j+1].profit/arr[j+1].weight))
            {
                item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;
            }
        }
    }
}

double fractionKnapsack(item *arr, int n, int W)
{
    int i = 0;
    double profit = 0;
    while(W > arr[i].weight)
    {
        W -= arr[i].weight;
        profit += arr[i].profit;
        i++;
    }
    if(W != 0)
    {
        profit += (((double)W/arr[i].weight)*arr[i].profit);
        W = 0;
    }
    return profit;
}

int main()
{
    item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    printf("Max Profit = %.2lf", fractionKnapsack(arr, 3, W));
    return 0;
}