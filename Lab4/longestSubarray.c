#include<stdio.h>
#include<stdlib.h>

void longestPalindrome(int *arr, int n, int *lb, int *ub)
{
    int i, j, k, max = 1;
    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            int flag = 1;

            for(k = 0; k < (j - i + 1)/2; k++)
            {
                if(arr[i+k] != arr[j - k])
                {
                    flag = 0;
                    break;
                }
            }

            if(flag && (j - i + 1) > max)
            {
                max = (j - i + 1);
                *lb = i;
                *ub = j;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 5, 3, 2, 1, 5, 6, 8, 9};
    int n = sizeof(arr)/sizeof(int);
    int lb, ub;
    longestPalindrome(arr, n, &lb, &ub);
    for(int i = lb; i <=ub; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}