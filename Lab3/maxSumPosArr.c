#include<stdio.h>
#include<stdlib.h>

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
    printf("Enter %d positive numbers: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Maximum proper subarray sum = %d\n", max(sum - arr[0], sum - arr[n - 1]));
    return 0;
}