#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:
    ll n;
    vector<unordered_set<ll>> adj;
    vector<ll> component;
    unordered_set<ll> openComponents;

    graph() {
        cin >> n;
        adj.resize(n);
        for (ll i=0; i<n; ++i) {
            ll a; cin >> a;
            a--;
            adj[i].insert(a);
            adj[a].insert(i);
        }
        component.resize(n, -1);
    }

    void dfs(ll u, ll c) {
        component[u] = c;
        if (adj[u].size() == 1 && component[*adj[u].begin()] == c) openComponents.insert(c);
        for (ll v: adj[u]) {
            if (component[v] == -1) {
                dfs(v, c);
            }
        }
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t; cin >> t;
    for (ll t_0 = 0; t_0 < t; ++t_0) {
        graph g;
        ll c = 0;
        for (ll i=0; i<g.n; ++i) {
            if (g.component[i] == -1) {
                g.dfs(i, c);
                c++;
            }
        }
        ll open = g.openComponents.size();
        cout << c-open+(open == 0 ? 0 : 1) << " " << c << endl;
    }
    return 0;
}