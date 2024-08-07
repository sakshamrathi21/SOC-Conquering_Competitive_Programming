#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    long long int n;
    cin>>n;
    vector <long long int> dp={1,2,4,8,16,32};
    ll i = 7;
    while (i<=n)
    {
        ll dp_i = 0;
        for (int i=dp.size()-6;i<dp.size();i++)
        {
            dp_i+=dp[i];
        }
        dp_i=dp_i%1000000007;
        // dp.erase(dp.begin());
        dp.push_back(dp_i);
        i++;
    }
    cout<<dp[n-1];
}