#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:
    ll n, k;
    vector<vector<ll>> adj;
    vector<ll> dfstree, subtree_size;

    graph() {
        cin >> n >> k;
        adj.resize(n);
        for(ll i=1; i<n; ++i) {
            ll p;
            cin >> p;
            p--;
            adj[p].push_back(i);
            adj[i].push_back(p);
        }
        subtree_size.resize(n, 0);
    }

    void dfs(ll node, ll parent) {
        // cout << "node: " << node << " parent: " << parent << "\n";
        dfstree.push_back(node);
        subtree_size[node] = 1;
        if(adj[node].size() == 1 && adj[node][0] == parent) return;
        for(auto v : adj[node]) {
            if(v != parent) {
                dfs(v, node);
                subtree_size[node] += subtree_size[v];
            }
        }
    }
};

int main () {
    graph g;
    g.dfs(0, -1);
    vector<ll> pos_in_dfstree(g.n);
    
    for (ll i=0; i<g.n; ++i) {
        pos_in_dfstree[g.dfstree[i]] = i;
    }

    ll k = g.k;
    for (ll t_0 = 0; t_0 < k; ++t_0) {
        ll u_i, k_i;
        cin >> u_i >> k_i;
        u_i--;
        if (k_i > g.subtree_size[u_i]) cout << "-1\n";    
        else {
            k_i--;
            cout << g.dfstree[pos_in_dfstree[u_i] + k_i] + 1 << "\n";
        }
    }
}