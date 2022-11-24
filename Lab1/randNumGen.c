#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    clock_t start, end;
    double totalTime;

    start = clock();
    printf("1000 randomly generated numbers:\n");
    for(int i = 0; i < 1000; i++){
        printf("%d ", rand());
    }
    end = clock();

    totalTime = (double)(end - start)/CLOCKS_PER_SEC;
    printf("\nTotal time taken: %lf", totalTime);
    return 0;
}