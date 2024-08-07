#include <bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long
#define pb push_back
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define nl "\n"
using namespace std;
int main() {
    ll n;
    cin>>n;
    vll dp(n+1,(ll)0);
    for(ll i=1;i<=n;i++){
      for(ll j=1;j<=6;j++){
        if(j>i) break;
        if(j==i) dp[i]++;
        dp[i] = (dp[i]+dp[i-j])%1000000007;
      }
    }
    cout<<dp[n]<<nl;
  return 0;
}