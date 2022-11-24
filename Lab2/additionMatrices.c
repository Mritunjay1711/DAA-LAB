#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, num;
    printf("Enter the dimension of matrix: ");
    scanf("%d", &n);
    printf("Enter the number of matrices: ");
    scanf("%d", &num);
    int mat[n][n], i, j, k;
    int **ans = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++)
    {
        ans[i] = (int *)calloc(n, sizeof(int));
    }

    printf("Enter the inputs for matrices: ");
    for (i = 0; i < num; i++)
    {
        printf("Matrix %d\n", i + 1);
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                scanf("%d", &mat[j][k]);
                ans[j][k] += mat[j][k];
            }
        }
    }

    printf("Result\n");
    for (j = 0; j < n; j++)
    {
        for (k = 0; k < n; k++)
        {
            printf("%d ", ans[j][k]);
        }
        printf("\n");
    }
    return 0;
}