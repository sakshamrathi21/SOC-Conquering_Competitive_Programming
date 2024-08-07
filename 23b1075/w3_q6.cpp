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




ll N,W;
ll sum=0;
cin>>N>>W;



    vll w(N),v(N);
    rp(N) {cin>>w[i]>>v[i]; sum+=v[i];}
   vector<ll> dp(sum+1,INT_MAX);
    dp[0]=0;
    for(ll i=0;i<N;i++){
        for(ll j=sum;j>=v[i];j--){
            if(dp[j-v[i]]!=INT_MAX)
            dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    ll ans=0;
    for(ll i=0;i<=sum;i++){
        if(dp[i]<=W)
        ans=max(ans,i);
    }
    cout<<ans<<endl;
}


