int main()
{
    clock_t start, end;
    double totalTime;
    start = clock();

    // int n;
    // printf("Enter the number of elements: ");
    // scanf("%d", &n);

    int arr[10000];
    // int arr[n];
    
    // printf("Enter the elements of array: ");
    // for(int i = 0; i < n; i++)
    //     scanf("%d", &arr[i]);

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