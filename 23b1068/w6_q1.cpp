#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define sz size
#define reach cout << "Reached" << endl;
#define o1(a) cout << a << "\n"
#define o2(a, b) cout << a << ' ' << b << "\n";
#define iArray(a, n) for (ll i = 0; i < n; i++) cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1000000007;

void sol(){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vll> adj(n+1);
    vll visited(n+1,0);
    for(ll i = 0; i < m; i++) {
        ll a,b;
        i2(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vll g(k),h(k);
    for(ll i = 0; i < k; i++) {
        i2(g[i],h[i]);
    }
    priority_queue<pll> q;
    vll dp(n+1,-1);
    for(ll i = 0; i < k; i++) {
        q.push({h[i],g[i]});
        dp[g[i]] = h[i];
    }
    while(!q.empty()){
        ll node = q.top().ss, p = q.top().ff;
        q.pop();
        if(dp[node]!=p) continue;
        for(ll child:adj[node]){
            if(dp[child]<p-1){
                dp[child] = p-1;
                q.push({p-1,child});
            }
        }
    }
    vll gaurded;
    for(ll i = 1; i <= n; i++) {
        if(dp[i]>=0) gaurded.pb(i);
    } 
    o1(gaurded.size());
    oArray(gaurded, gaurded.size());



}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
