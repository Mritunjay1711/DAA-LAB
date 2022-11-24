#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}


int lcs(char *arr1, int n1, char *arr2, int n2)
{
    int dp[n1+1][n2+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            if(arr1[i-1] == arr2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                printf("%d-%c ", dp[i][j], 'T');
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                printf("%d-%c ", dp[i][j], dp[i][j-1] > dp[i-1][j] ? 'L' : 'U');
            }
        }
        printf("\n");
    }
    return dp[n1][n2];
}


int main()
{
    int n1, n2;
    printf("Enter the length of  first string: ");
    scanf("%d", &n1);
    char str1[n1];
    printf("Enter the string: ");
    scanf("%s", str1);
    printf("Enter the length of second string: ");
    scanf("%d", &n2);
    char str2[n2];
    printf("Enter the string: ");
    scanf("%s", str2);
    printf("Length of longest subsequence: %d\n", lcs(str1, n1, str2, n2));
    return 0;
}