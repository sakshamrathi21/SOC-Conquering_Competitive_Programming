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
ll x,n;
cin>>x>>n;
priority_queue<ll,vector<ll>,greater<ll>> pq;
rp(n) {ll y; cin>>y; pq.push(y);
}
ll ans=0;
while(true)
{
    ll a=pq.top();
    pq.pop();
    if(pq.empty()) break;
    ll b=pq.top();
    pq.pop();
      ans+=a+b;
    pq.push(a+b);
}
cout<<ans<<endl;
}