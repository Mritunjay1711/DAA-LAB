//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int solve(string S, int i, int j, bool isTrue)
    {
        if(i > j)
            return 0;
        if(i == j)
        {
            if(isTrue)
                return S[i] == 'T';
            else
                return S[i] == 'F';
        }
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue] % 1003;
            
        int result = 0;
        
        for(int k = i + 1; k <= j - 1; k+=2)
        {
            int lt, rt, lf, rf;
            
            if(dp[i][k-1][1] != -1)
                lt = dp[i][k-1][1];
            else
                lt = solve(S, i, k - 1, true);
            
            if(dp[i][k-1][0] != -1)
                lf = dp[i][k-1][0];
            else
                lf = solve(S, i, k-1, false);
            
            if(dp[k+1][j][1] != -1)
                rt = dp[k+1][j][1];
            else
                rt = solve(S, k+1, j, true);
                
            if(dp[k+1][j][0] != -1)
                rf = dp[k+1][j][0];
            else
                rf = solve(S, k+1, j, false);
            
            if(S[k] == '&')
            {
                if(isTrue)
                    result += lt * rt;
                else
                    result += ((lt * rf)+(lf * rt)+(lf * rf));
            }
            
            if(S[k] == '|')
            {
                if(isTrue)
                    result += ((lt*rf)+(lf*rt)+(lt*rt));
                else
                    result += lf*rf;
            }
            
            if(S[k] == '^')
            {
                if(isTrue)
                    result += ((lt*rf)+(lf*rt));
                else
                    result += ((lf*rf)+(lt*rt));
            }
            
            dp[i][j][isTrue] = result%1003;
        }
        return dp[i][j][isTrue]%1003;
    }
    int countWays(int N, string S){
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(S, 0, S.length()-1, true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends