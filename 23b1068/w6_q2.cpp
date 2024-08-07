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

void dfs(ll node, vector<vll> adj, vll& visited, ll parent, vll& path, bool& found){
    if(found) return;
    if(visited[node]){
        if(path.size()>1){
            found = true;
            path.pb(node);
            for(ll i=0; i<path.size(); i++) cout << path[i] << ' ';
            return;
        }
        else return;
    }
    visited[node] = true;
    for(auto child:adj[node]){
        if(child ==parent) continue;
        path.pb(node);
        dfs(child,adj,visited,node,path,found);
        if(!found) path.pop_back();
    }

    
}


void sol(){
    ll n,m;
    i2(n,m);
    vector<vll> adj(n+1,vector<ll>(0));
    for(ll i = 0; i < m; i++) {
        ll a,b;
        i2(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<ll> visited(n+1,0);
    vll path;
    bool found = false;
    for(ll i = 1; i <= n; i++) {
        if(visited[i]) continue;
        path.pb(i);
        dfs(i,adj, visited, -1, path, found);
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
