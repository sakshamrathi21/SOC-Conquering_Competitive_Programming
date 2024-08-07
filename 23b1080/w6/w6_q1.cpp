#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:
    ll n, m, k;
    vector<vector<ll>> adj;
    vector<ll> x, d, p, h;
    priority_queue<pair<ll, ll>> Q;

    graph () {
        cin >> n >> m >> k;
        adj.resize(n);
        for (ll i=0; i<m; ++i ) {
            ll a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        x.resize(n, -1); d.resize(n, -1);
        p.resize(k); h.resize(k);
        for (ll i=0; i<k; ++i ) {
            ll p_i, h_i; cin >> p_i >> h_i;
            p_i--;
            x[p_i] = h_i;
            p[i] = p_i; h[i] = h_i;
        }
    }

    void add (ll v, ll x) {
        if (d[v] < x) Q.emplace(d[v] = x, v);
    }

    void calculate () {
        for(ll i=0; i<k; ++i) add(p[i], h[i]);
        while (Q.size()) {
            auto [x, v] = Q.top(); Q.pop();
            if (d[v] != x) continue;
            for (ll u: adj[v]) add(u, d[v]-1);
        }
    }
};

int main () {
    graph g;
    g.calculate();
    vector<ll> ans;
    for (ll i=0; i<g.n; ++i) {
        if (g.d[i] >= 0) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for (ll i: ans) cout << i << " ";
    cout << endl;
}