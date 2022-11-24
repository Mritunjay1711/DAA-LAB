#include<stdio.h>
#include<stdlib.h>

void maxMin(int *A, int i, int j, int *max, int *min)
{
    if(i == j)
    {
        *max = A[i];
        *min = A[i];
        return;
    }
    if(i == j - 1)
    {
        if(A[i] > A[j])
        {
            *max = A[i];
            *min = A[j];
        }
        else
        {
            *max = A[j];
            *min = A[i];
        }
        return;
    }
    int max1, min1, mid;
    mid = (i + j)/2;
    maxMin(A, i, mid, max, min);
    maxMin(A, mid+1, j, &max1, &min1);

    if(*max < max1)
        *max = max1;
    if(*min > min1)
        *min = min1;   
}

int main()
{
    int n, max, min;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    maxMin(A, 0, n - 1, &max, &min);
    printf("Max = %d\nMin = %d\n", max, min);
    return 0;
}