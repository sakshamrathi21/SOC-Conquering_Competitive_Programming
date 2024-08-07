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

void dfsForTopSort(int s, vll& visited, vector<vll>& adj, stack<ll>& stk) {
    if (visited[s]) return;
    visited[s] = true;
    // process node s
    vll ans;
    for (auto u: adj[s]) {
        dfsForTopSort(u, visited, adj, stk);
    }
    stk.push(s);
}

vll topoSort(vector<vll> adj, vll& processed){
    ll n=adj.size()-1;
    stack<ll> stk;
    for(ll node=1; node<=n; node++ ){
        if(processed[node]) continue;
        dfsForTopSort(node,processed,adj,stk);
    }
    vll ans;

    while(!stk.empty()){
        ans.pb(stk.top());
        stk.pop();
    }
    return ans;
}

void sol(){
    ll n,m;
    i2(n,m);
    vector<vll> adj(n+1);
    vll visited(n+1,0);
    for(ll i = 0; i < m; i++) {
        ll a,b;
        i2(a,b);
        adj[a].pb(b);
    }

    vll sorted = topoSort(adj,visited);
    vll dp(n+1,0);
    for( ll node:sorted){
        for(ll child: adj[node]){
            dp[child] = max(dp[child],dp[node]+1);
        }
    }
    auto x = max_element(dp.begin(),dp.end());
    o1(*x);


}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
