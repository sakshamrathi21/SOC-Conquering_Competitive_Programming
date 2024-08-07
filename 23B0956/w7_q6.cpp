#include <bits/stdc++.h>
using namespace std;

const int N = 501;
long long dp[N][N];
string s;

long long minOps(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l > r)
    {   
        dp[l][r]=0;
        return 0;
    }
        
    if (l == r)
    {
        dp[l][r]=1;
        return 1;
    }
    long long ans = 1 + minOps(l + 1, r);
    for (int i = l + 1; i <= r; i++)
    {
        if (s[i] == s[l])
        {
            ans = min(ans, minOps(l+1, i - 1) + minOps(i, r));
        }
    }
    dp[l][r] = ans;
    return dp[l][r];
}

int main()
{
    int n;
    cin >> n;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    // cout<<s.length();
    cout << minOps(0, n - 1);
    // for(int i=0;i<N;i++)
    // {
    //     for(int j=0;j<N;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}