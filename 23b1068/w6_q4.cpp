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

void dfs(vector<vll>& adj, vll& visited, ll start, bool& k){
    visited[start] = 1;
    if(adj[start].size()==1) k=true;
    for(auto c:adj[start]){
        if(visited[c]) continue;
        dfs(adj,visited,c,k);
    }
}



void sol(){
    ll n;
    cin >> n;
    vector<vll> adj(n+1);
    for(ll i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        if(adj[a].size()==0){
            adj[a].pb(i);
            adj[i].pb(a);
        }
        else if(adj[a].size()==1 && adj[a][0]!=i){
            adj[a].pb(i);
            adj[i].pb(a);
        }        
    }
    vll visited(n+1,0);
    ll emptyCompCount = 0;
    ll compCount = 0;
    for(ll i = 1; i <= n; i++) {
        if(!visited[i]){
            bool yo =false;
            dfs(adj,visited,i,yo);
            if(yo) emptyCompCount++;
            compCount++;
        }
    }
    ll mn = compCount - emptyCompCount+1;
    if(emptyCompCount== 0 )mn--;
    o2(mn,compCount)

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        sol();
    }
}
