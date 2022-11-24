#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int linearSearch(int *arr, int n, int ind, int key){
    if(ind == n)
        return -1;
    if(arr[ind] == key)
        return ind;
    return linearSearch(arr, n, ind+1, key);
}


int binarySearch(int *arr, int i, int j, int key){
    if(i > j)
        return -1;
    int mid = (i+j)/2;
    if(arr[mid] == key)
        return mid;
    else if(arr[mid] < key)
        return binarySearch(arr, mid + 1, j, key);
    else 
        return binarySearch(arr, i, mid - 1, key);
}


int main()
{
    clock_t start, end;
    double totalTime;
    int arr[10000], key, ind;

    printf("Enter a number in range 1-10000 to search: ");
    scanf("%d", &key);
    start = clock();

    for(int i = 0; i < 10000; i++){
        arr[i] = rand() % 10000;
    }

    ind = linearSearch(arr, 10000, 0, key);
    if(ind == -1)
        printf("Key not found!\n");
    else   
        printf("Key found at %d index\n", ind);

    end = clock();

    totalTime = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken for linear search = %lf\n", totalTime);


    printf("Enter the key in range 1-20000 to search: ");
    scanf("%d", &key);
    start = clock();
    int j = 1;
    ind = -1;

    for(int i = 0; i < 10000; i++){
        arr[i] = j;
        j+=2;
    }
    
    ind = binarySearch(arr, 0, 9999, key);
    
    if(ind == -1)
        printf("Key not found!\n");
    else   
        printf("Key found at %d index\n", ind);
    end = clock();

    totalTime = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time taken for binary search = %lf\n", totalTime);
    
    return 0;
}