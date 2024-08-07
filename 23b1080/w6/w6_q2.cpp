#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:
    ll n, m, nc;
    vector<vector<ll>> adj;
    vector<ll> component, level, parent;
    vector<pair<ll, ll>> edges;

    graph () {
        cin >> n >> m;
        adj.resize(n);
        for (ll i=0; i<m; ++i) {
            ll a_i, b_i;
            cin >> a_i >> b_i;
            a_i--; b_i--;
            adj[a_i].push_back(b_i);
            adj[b_i].push_back(a_i);
            edges.push_back({a_i, b_i});
        }
        component.resize(n, -1);
        level.resize(n, -1);
        parent.resize(n, -1);
    }

    void bfs(ll root, ll c) {
        queue<ll> q;
        q.push(root);
        level[root] = 0;
        component[root] = c;
        while(!q.empty()) {
            ll node = q.front();
            q.pop();
            for (auto i : adj[node]) {
                if (component[i] == -1) {
                    component[i] = c;
                    level[i] = level[node] + 1;
                    parent[i] = node;
                    q.push(i);
                }
            }
        }
    }

    void connected_components() {
        nc = 0;
        for (ll i=0; i<n; ++i) {
            if (component[i] == -1) {
                bfs(i, nc);
                nc++;
            }
        }
    }

    vector<ll> find_cycle() {
        for (auto edge : edges) {
            auto [a, b] = edge;
            if (parent[a] != b && parent[b] != a) {
                // cout << "Cycle edge: " << a << " " << b << endl;
                vector<ll> aToCommonAncestor, bToCommonAncestor;
                while (a != b) {
                    if (level[a] > level[b]) {
                        aToCommonAncestor.push_back(a);
                        // cout << "pushed " << a << " to aToCommonAncestor\n";
                        a = parent[a];
                    } else {
                        bToCommonAncestor.push_back(b);
                        // cout << "pushed " << b << " to bToCommonAncestor\n";
                        b = parent[b];
                    }
                }
                aToCommonAncestor.push_back(a);
                vector<ll> cycle = aToCommonAncestor;
                reverse(bToCommonAncestor.begin(), bToCommonAncestor.end());
                cycle.insert(cycle.end(), bToCommonAncestor.begin(), bToCommonAncestor.end());
                return cycle;
            }
        }
        return {};
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    graph g;
    g.connected_components();
    vector<ll> cycle = g.find_cycle();
    if (!cycle.empty()) {
        cout << cycle.size()+1 << "\n";
        for (auto node : cycle) {
            cout << node+1 << " ";
        }
        cout << cycle[0]+1;
        cout << endl;
    }
    else cout << "IMPOSSIBLE\n";
    // for (ll i=0; i<g.n; ++i) cout << i << " : " << g.level[i] << " " << g.component[i] << endl;
}