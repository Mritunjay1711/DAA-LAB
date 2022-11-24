#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int *arr, int n, int start, int end)
{
    if (n == end)
        return;
    else if (start > end)
        printArray(arr, n, 0, end + 1);
    else
    {
        printf("[");
        for (int i = start; i < end; i++)
        {
            printf("%d, ", arr[i]);
        }
        printf("%d]\n", arr[end]);
        printArray(arr, n, start + 1, end);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    double subset = n * (n + 1)/2;

    printf("Total subsets = %.0lf\n", subset);
    printf("Total proper subsets = %.0lf\n", subset - 1);
    printf("Proper subsets are: \n");
    printArray(arr, n, 0, 0);
    return 0;
}