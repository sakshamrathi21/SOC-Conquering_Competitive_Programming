#include<bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long int
#define mod 1000000007
using namespace std;
int main() {
ll n,q;
cin>>n>>q;
vector<ll> a(n);
vector<ll> dp(n,0);
ll sum=0;
rp(n) {cin>>a[i]; sum+=a[i]; dp[i]=sum;
}
rp(q){
 
    ll a,b;
    cin>>a>>b;
    cout<<dp[b-1]-(a>1?dp[a-2]:0)<<endl;
}
}