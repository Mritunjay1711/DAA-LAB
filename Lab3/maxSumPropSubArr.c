#include<stdio.h>
#include<stdlib.h>


int sumSubarray(int *arr, int i, int j)
{
    int maxSoFar = 0, maxNow = 0;
    for(int k = i; k <= j; k++)
    {
        maxNow += arr[k];
        if(maxNow > maxSoFar){
            maxSoFar = maxNow;
        }
        if(maxNow < 0)
            maxNow = 0;
    }
    return maxSoFar;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n], sum = 0;
    printf("Enter %d numbers: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Maximum sum of proper subarray = %d\n", max(sumSubarray(arr, 0, n - 2), sumSubarray(arr, 1, n - 1)));

    return 0;
}