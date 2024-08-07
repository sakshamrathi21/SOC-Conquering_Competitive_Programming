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

ll bfs(vector<vll>& adj, vll& visited, ll start){
    queue<ll> q;
    q.push(start);
    visited[start] = 0;
    ll mx=0;
    while(!q.empty()){
        ll a=q.front();
        q.pop();
        for(ll child:adj[a]){
            if(visited[child]>=0) continue;
            visited[child] = visited[a]+1;
            mx = child;
            q.push(child);
        }
    }
    return mx;
}

void sol(){
    ll n;
    cin >> n;
    
    vector<vll> adj(n+1);
    if(n==1){
        o1(0);
        return;
    }
    for(ll i = 0; i < n; i++) {
        ll a,b;
        i2(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    vll distanceFrom1(n+1,-1);
    ll d_start = bfs(adj,distanceFrom1,1);
    vll distanceFromStart(n+1,-1);
    ll d_end = bfs(adj,distanceFromStart,d_start);
    vll distanceFromEnd(n+1,-1);
    ll faltu = bfs(adj,distanceFromEnd,d_end);
    for(ll i = 1; i <= n; i++) {
        cout << max(distanceFromStart[i],distanceFromEnd[i]) << ' ';
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
