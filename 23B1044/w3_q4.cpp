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
  string a,b;
    cin>>a>>b;
    vector<vll> dp(a.size()+1,vector<ll>(b.size()+1,0));
    rp(a.size()+1) dp[i][0]=i;
    rpv(b.size()+1,j) dp[0][j]=j;
    for (ll i=1;i<=a.size();i++){
        for(ll j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
        }
    }
    // for (auto x:dp){
    //     for(auto y:x) cout<<y<<" ";
    //     cout<<nl;
    // }
    cout<<dp[a.size()][b.size()]<<nl;
  return 0;
}