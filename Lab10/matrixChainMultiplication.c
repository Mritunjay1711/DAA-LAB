#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dp[100][100];

int min(int a, int b)
{
    return a < b ? a : b;
}

int solve(int *p, int i, int j)
{
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int mini = __INT_MAX__, count;
    for(int k = i; k < j; k++)
    {
        count = (solve(p, i, k) + solve(p, k+1, j) + (p[i-1]*p[k]*p[j]));           
        mini = min(mini, count);
    }
    return dp[i][j] = mini;
}

int main()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n+1];
    printf("Enter the values of P: ");
    for(int i = 0; i < n+1; i++)
        scanf("%d", &p[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(p, 1, n));
    return 0;
}