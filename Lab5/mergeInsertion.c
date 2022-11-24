#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int threshold = 16;

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

void insertionSort(int *A, int lb, int ub)
{
    int key, j;
    for(int i = lb + 1; i <= ub; i++)
    {
        key = A[i];
        j = i - 1;

        while(j >= lb && key < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
       
    }
}

void mergeSort(int *arr, int lb, int ub)
{
    if(ub-lb <= threshold)
        insertionSort(arr, lb, ub);
    else{
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
    int arr[100000];
    int j = 10000000;
    for(int i = 0; i < 100000; i++)
    {
        arr[i] = j;
        j -= 3;
    }

    mergeSort(arr, 0, 99999);
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken = %lf\n", timeTaken);
    // for(int i = 0; i < 10000; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    return 0;
}