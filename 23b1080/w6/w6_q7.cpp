#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {
    public:
    ll n;
    vector<vector<ll>> adj;
    vector<ll> firstMax, secondMax, child1, child2;

    void input () {
        cin >> n;
        adj.resize(n);
        for (ll i = 0; i < n-1; i++) {
            ll a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        firstMax.resize(n, 0);
        secondMax.resize(n, 0);
        child1.resize(n, -1);
        child2.resize(n, -1);
    }

    void dfs1 (ll u, ll p) {
        for (ll v: adj[u]) {
            if (v==p) continue;
            dfs1(v, u);
            if (firstMax[v]+1 > firstMax[u]) {
                secondMax[u] = firstMax[u];
                firstMax[u] = firstMax[v]+1;
                child1[u] = v;
            } else if (firstMax[v]+1 > secondMax[u]) {
                secondMax[u] = firstMax[v]+1;
                child2[u] = v;
            }
        }
    }

    void dfs2 (ll v, ll p) {
        for (auto x : adj[v]) {
		    if (x == p) continue;
		    if (child1[v] == x) {
		    	if (firstMax[x] < secondMax[v] + 1) {
		    		secondMax[x] = firstMax[x];
		    		firstMax[x] = secondMax[v] + 1;
		    		child1[x] = v;
		    	} else {
		    		secondMax[x] = max(secondMax[x], secondMax[v] + 1);
		    	}
		    } else {
		    	secondMax[x] = firstMax[x];
		    	firstMax[x] = firstMax[v] + 1;
		    	child1[x] = v;
		    }
		    dfs2(x, v);
	    }
    }
};

int main () {
    graph g;
    g.input();
    g.dfs1(0, -1);
    g.dfs2(0, -1);
    for (ll i = 0; i < g.n; i++) {
        cout << max(g.firstMax[i], g.secondMax[i]) << " ";
    }
    cout << endl;
    return 0;
}