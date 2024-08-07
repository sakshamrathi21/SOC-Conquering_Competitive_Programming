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
ll n,m,k;
cin>>n>>m>>k;
vll adj[n+1];
rp(m) {
    ll x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
vll p(k),c(k);
rp(k) cin>>p[i]>>c[i];
priority_queue<pair<int,int>> pq;
vll processed(n+1,0);
vll x(n+1,-1);
rp(k){ x[p[i]]=c[i];
pq.push({c[i],p[i]});
}

while(!pq.empty()){
  int cost=pq.top().first;
    int node=pq.top().second;
    pq.pop();
    if(processed[node]) continue;
    processed[node]=1;
    for(auto i:adj[node]){
       
            x[i]=max(x[node]-1,x[i]);
            pq.push({x[i],i});
        
    }
}
vll ans;
rp(n) if(x[i+1]!=-1) ans.push_back(i+1);
cout<<ans.size()<<endl;
rp(ans.size()) cout<<ans[i]<<" ";






}