#include <bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long
#define pb push_back
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define nl "\n"
using namespace std;
#define MOD 1000000007
int main() {
    ll n;
    n=10e6;
    // vector<pair<ll,ll>> dp(n+1,{0,0});
    // dp[0]={1,1};
    vll dp(n+1,0);
    vll np(n+1,0);
    vll sum(n+2,0);
    sum[0]=0;
    sum[1]=1;
    sum[2]=3;
    dp[0]=1;
    dp[1]=2;
    np[0]=0;
    np[1]=1;


    for(ll i=2;i<=n;i++){
        np[i]=(dp[i-1]+3*np[i-1])%MOD;
        dp[i]=(sum[i]+np[i])%MOD;
        sum[i+1]=(sum[i]+dp[i])%MOD;
    }
    // for(auto x:np) cout<<x<<" ";
    // cout<<nl;
    // for(auto x:sum) cout<<x<<" ";
    // cout<<nl;
    // for(auto x:dp) cout<<x<<" ";
    // cout<<nl;
  int TestCases;
  cin >> TestCases;
  while (TestCases--) {
    ll x;
    cin>>x;
    cout<<dp[x]<<nl;
    }
  return 0;
}