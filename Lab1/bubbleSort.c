#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = 0 ; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    clock_t start, end;
    double totalTime;
    start = clock(); 

    int arr[10000];

    //For random input
    for(int i = 0; i < 10000; i++){
        arr[i] = rand();
    }

    


    bubbleSort(arr, 10000);
    // printArray(arr, 1000);
    end = clock();

    totalTime = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken by the code for random input = %lf\n", totalTime);

    start = clock();
    // For sorted input
    int j = 1;
    for(int i = 0; i < 10000; i++){
        arr[i] = j;
        j+=3;
    }
    
    bubbleSort(arr, 10000);
    end = clock();

    totalTime = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken by the code for sorted input = %lf\n", totalTime);


    start = clock();

    //Reverse sorted
    int k = 30000;
    for(int i = 0; i < 10000; i++){
        arr[i] = k;
        k-=3;
    }

    bubbleSort(arr, 10000);
    end = clock();

    totalTime = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken by the code for reverse sorted input = %lf\n", totalTime);
    return 0;
}