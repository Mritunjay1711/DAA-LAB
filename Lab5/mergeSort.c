#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *arr, int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int size = ub + 1;
    int B[size];
    while (i <= mid && j <= ub)
    {
        if(arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++; 
            k++;
        }
        else
        {
            B[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid)
    {
        B[k] = arr[i];
        i++; 
        k++;
    }
    while(j <= ub)
    {
        B[k] = arr[j];
        j++;
        k++;
    }
    for(i = lb; i <= ub; i++)
    {
        arr[i] = B[i];
    }
}

void mergeSort(int *arr, int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb+ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    clock_t start, end;
    double timeTaken;
    start = clock();
    int arr[5000];

    int j = 100000;
    for(int i = 0; i < 5000; i++)
    {
        arr[i] = j;
        j -= 4;
    }

    mergeSort(arr, 0, 4999);
    // for(int i = 0; i < 500; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken = %lf\n", timeTaken);

    return 0;
}