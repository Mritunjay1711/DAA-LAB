#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int *A, int n, int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int maxInd;
    if(l < n && A[l] > A[i])
        maxInd = l;
    else
        maxInd = i;
    
    if(r < n && A[r] > A[maxInd])
        maxInd = r;
    
    if(maxInd != i)
    {
        swap(&A[i], &A[maxInd]);
        maxHeapify(A, n, maxInd);
    }
}

void buildMaxHeap(int *A, int n)
{
    for(int i = n/2; i >= 0; i--)
    {
        maxHeapify(A, n, i);
    }
}

void heapSort(int *A, int n)
{
    buildMaxHeap(A, n);
    for(int i = n - 1; i >= 0; i--)
    {
        //Swapping first and last element
        swap(&A[0], &A[i]);
        maxHeapify(A, i, 0);
    }
}

int main()
{
    clock_t start, end;
    double timeTaken;
    start = clock();
    int arr1[5000];

    for(int i = 0; i < 5000; i++)
    {
        arr1[i] = rand();
    }
    heapSort(arr1, 5000);
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken for 5000 inputs = %lf\n", timeTaken);

    start = clock();
    int arr2[10000];

    for(int i = 0; i < 10000; i++)
    {
        arr2[i] = rand();
    }
    heapSort(arr2, 10000);
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken for 10000 inputs = %lf\n", timeTaken);

    start = clock();
    int arr3[50000];

    for(int i = 0; i < 50000; i++)
    {
        arr3[i] = rand();
    }
    heapSort(arr3, 50000);
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken for 50000 inputs = %lf\n", timeTaken);


    start = clock();
    int arr4[100000];

    for(int i = 0; i < 100000; i++)
    {
        arr4[i] = rand();
    }
    heapSort(arr4, 100000);
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken for 100000 inputs = %lf\n", timeTaken);
    return 0;
}