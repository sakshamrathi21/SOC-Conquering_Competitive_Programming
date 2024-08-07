#include<bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long int
typedef std::vector<ll> vll;
#define o1(a) cout<<a<<endl;
#define mod 1000000007
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
string x,y;
cin>>x>>y;
ll n=x.size(),m=y.size();
vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
rp(n+1) dp[i][0]=i;
rp(m+1) dp[0][i]=i;
for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
        if(x[i-1]==y[j-1]) dp[i][j]=dp[i-1][j-1];
        else dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
    }
}
cout<<dp[n][m]<<endl;
}