#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int lb, int ub)
{
    int pivot = arr[lb];
    int i = lb + 1, j = ub;
    while(i <= j)
    {
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[lb]);
    return j;
}


void quickSort(int *arr, int lb, int ub)
{
    if(lb <= ub)
    {
        int ind = partition(arr, lb, ub);
        quickSort(arr, lb, ind-1);
        quickSort(arr, ind+1, ub);
    }
}

int main()
{
    clock_t start, end;
    double timeTaken;
    printf("Enter the number of inputs: "); 
    int n;
    scanf("%d", &n);
    start = clock();
    int arr[n];
    time_t t;

    for(int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    quickSort(arr, 0, n-1);
    
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken for random input= %lf\n", timeTaken);

    return 0;
}