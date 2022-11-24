#include<stdio.h>
#include<stdlib.h>

void cofactor(int arr[3][3], int cof[3][3], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i + j) % 2 == 0){
                cof[i][j] = (arr[(i + 1) % 3][(j + 1) % 3] * arr[(i + 2)%3][(j + 2) % 3]) - (arr[(i + 1) % 3][(j+2) %3]*arr[(i + 2) % 3][(j + 1) % 3]);
            }
            else
            {
                cof[i][j] = -(-(arr[(i+1) % 3][(j+1) % 3]*arr[(i+2) % 3][(j + 2) %3]) + (arr[(i + 1) % 3][(j + 2) % 3]*arr[(i + 2) % 3][(j + 1) % 3]));
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transpose(int arr[3][3], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            swap(&arr[i][j], &arr[j][i]);
        }
    }
}

int main()
{
    
    int arr[3][3], cof[3][3];
    printf("Enter the value in matrix: \n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    cofactor(arr, cof, 3);
    transpose(cof, 3);
    printf("Adjoint\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", cof[i][j]);
        }
        printf("\n");
    }
    return 0;
}