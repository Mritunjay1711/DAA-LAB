#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int i = 0, j = 0;
        int n = S.length(), l = W.length();
        int count = 0, c2= 0;
        string ans = "";
        while(i < n)
        {
            while(i < n && S[i]!=W[j])
                i++;
            // cout << i << "* ";
            if(S[i] && S[i] == W[j] && j != l-1)
            {
                ans += S[i];
                c2++;
                S[i] = '*';
                i++;
                j++;
            }
            else if(S[i] == W[j] && j == l-1)
            {
                cout << S[i] << " " << i << " " << j << endl;
                c2++;
                ans += S[i];
                S[i] = '*';
                cout << ans << endl;
                ans = "";
                i++;
                j = 0;
                count++;
            }
        }
        cout << S << " " << c2 << endl;
        return count;
    }
};


int main(){
    string s1 = "gqeuelpumprokpzmutmrimebihkgexxmnegtpxpdmiryxqnrkblsnpvxwhfcecqtgwoxteaimtgmkvfwwqqjflidsnhyqzryxfwrlybasjmeftabksnrdvxxjgvbgmzdtxwfyzfsjrwqmytwqiqvensptpsbdthwrdbpdihozfemdzkviaqopkflzxmcqtajzcaekjsmoyatxmohpgvesaprzevqzwbyaccmnwaeucxurobgwzkpzcgzgerfcugeyismhvqdxpzodbwachpbjxcrdvwfsclqneewzuzykbppelrguijfgowjjvrdzeuoiykjvmkhnzwrmqxhygoeulqgijjhnfwygihdurkhsiafyxoxgcdcpvixguhubfuhnbkivwrnfsudrkcxpicedkekgngisarfdepyahohbknuvpumxwqdgwpplvxdxqjcuadxhrekdrfajzmivfnddcspzrsykdbeeebnxiyabf";
    string s2 = "zxeewferfrdgregerg";
    cout << s1.length() << endl;
    cout << s1[254] << "* " << s1[1159] << "*" << endl;
    Solution ob;
    cout << ob.numberOfSubsequences(s1, s2);

    return 0;
}