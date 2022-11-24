#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[100][100][2];
int solve(char *S, int i, int j, int isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return S[i] == '1';
        else
            return S[i] == '0';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int result = 0;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt, rt, lf, rf;

        if (dp[i][k - 1][1] != -1)
            lt = dp[i][k - 1][1];
        else
            lt = solve(S, i, k - 1, 1);

        if (dp[i][k - 1][0] != -1)
            lf = dp[i][k - 1][0];
        else
            lf = solve(S, i, k - 1, 0);

        if (dp[k + 1][j][1] != -1)
            rt = dp[k + 1][j][1];
        else
            rt = solve(S, k + 1, j, 1);

        if (dp[k + 1][j][0] != -1)
            rf = dp[k + 1][j][0];
        else
            rf = solve(S, k + 1, j, 0);

        if (S[k] == '&')
        {
            if (isTrue)
                result += lt * rt;
            else
                result += ((lt * rf) + (lf * rt) + (lf * rf));
        }

        if (S[k] == '^')
        {
            if (isTrue)
                result += ((lt * rf) + (lf * rt));
            else
                result += ((lf * rf) + (lt * rt));
        }

        dp[i][j][isTrue] = result;
    }
    return dp[i][j][isTrue];
}

int main()
{
    char arr[] = "1&0^1";
    int n = sizeof(arr);
    n--;
    memset(dp, -1, sizeof(dp));
    printf("No of ways for T result = %d\n", solve(arr, 0, n-1, 1));
    return 0;
}