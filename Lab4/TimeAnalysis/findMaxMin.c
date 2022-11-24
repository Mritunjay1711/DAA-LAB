#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Divide and conquer
void findMaxMinDnC(int *A, int lb, int ub, int *max, int *min)
{
    //Only one element
    if(lb == ub)
    {
        *max = A[lb];
        *min = A[ub];
        return;
    }
    //Two elements
    if(lb == ub - 1)
    {
        if(A[lb] > A[ub])
        {
            *max = A[lb];
            *min = A[ub];
        }
        else
        {
            *min = A[ub];
            *max = A[lb];
        }
        return;
    }
    else
    {
        int mid = (lb + ub)/2;
        int max1, min1;
        findMaxMinDnC(A, lb, mid, max, min);
        findMaxMinDnC(A, mid + 1, ub, &max1, &min1);
        if(*max < max1)
            *max = max1;
        if(*min > min1)
            *min = min1;
    }
}


//Using loop
void findMaxMinLoop(int *A, int n, int *max, int *min)
{
    //Initialing variables
    *max = 0;
    *min = 10000000;

    for(int i = 0; i < n; i++)
    {
        if(A[i] > *max)
            *max = A[i];
        if(A[i] < *min)
            *min = A[i];
    }
}

int main()
{
    clock_t start, end;
    double timeTaken;

    int n;
    printf("Enter the number of inputs: ");
    scanf("%d", &n);
    int A[n], max, min;
    for(int i = 0; i < n; i++)
    {
        //Assigning random value between 0-100000
        A[i] = rand()%100000;
    }
    
    //Starting clock for divide and conquer
    start = clock();
    findMaxMinDnC(A, 0, n-1, &max, &min);
    printf("Max= %d\nMin= %d\n", max, min);
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken by divide and conquer: %lf\n", timeTaken);


    //Starting clock for loop method
    start = clock();
    findMaxMinLoop(A, n, &max, &min);
    printf("Max= %d\nMin= %d\n", max, min);
    end = clock();
    timeTaken = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken by loop: %lf\n", timeTaken);
    return 0;
}