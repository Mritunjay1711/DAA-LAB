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
    if(lb < ub)
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
    start = clock();
    int arr[10] = {98, 89, 34, 2, 33, 18, 29, 56, 9, 7};
    time_t t;

    srand((unsigned) time(&t));
    // int j = 100000;
    for(int i = 0; i < 500; i++)
    {
        arr[i] = rand();
        // j-=4;
    }
    // // printf("Running\n");
    quickSort(arr, 0, 9);
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken = %lf\n", timeTaken);

    return 0;
}