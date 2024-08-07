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
#define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1000000007;

ll nChild(vll& dp, ll start, vector<vll>& adj) {
    if(dp[start] != -1) return dp[start];
    ll ans = 0; 
    for(ll c : adj[start]) {
        ans += 1 + nChild(dp, c, adj); 
    }
    dp[start] = ans;
    return ans;
}

void dfsTree(vector<vll>& adj, vll& route, vector<ll>& startIdx, ll s, ll& idx) {
    startIdx[s] = idx;
    route.pb(s);
    idx++;
    for(ll child: adj[s]) {
        dfsTree(adj, route, startIdx, child, idx);
    }
}

void sol() {
    ll n, q;
    i2(n, q);
    vector<vll> adj(n + 1);
    for(ll i = 2; i <= n; i++) {
        ll a;
        cin >> a;
        adj[a].pb(i);
    }
    
    vll dp(n + 1, -1);
    nChild(dp, 1, adj); // Populate dp array with the number of children
    
    vll route;
    vector<ll> startIdx(n + 1, -1);
    ll idx = 0;
    dfsTree(adj, route, startIdx, 1, idx);

    while(q--) {
        ll a, b;
        cin >> a >> b;
        if (b > dp[a]+1) {
            cout << -1 << "\n";
        } else {
            cout <<(route[startIdx[a] + b - 1]) << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
