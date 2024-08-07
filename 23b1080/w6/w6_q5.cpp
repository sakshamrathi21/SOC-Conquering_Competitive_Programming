#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class graph {		
	public:
	ll n,m;
	vector<vector<ll>> adj, radj;
	vector<ll> maxLength;

	void input() {
		cin >> n >> m;
		adj.resize(n);
		radj.resize(n);
		maxLength.resize(n, -1);
		for(ll i=0; i<m; ++i) {
			ll a,b;
			cin >> a >> b;
			a--; b--;
			adj[a].push_back(b);
			radj[b].push_back(a);
		}
	}

	void calcMaxLength(ll u) {
		if (maxLength[u] != -1) return;
		if (adj[u].size() == 0) {
			maxLength[u] = 0;
			return;
		}
		ll maxi = -1;
		for (auto v : adj[u]) {
			if (maxLength[v] == -1) calcMaxLength(v);
			maxi = max(maxi, maxLength[v]+1);
		}
		maxLength[u] = maxi;
		return;
	}
};

int main () {
	graph g;
	g.input();

	// maximum maxLength
	ll maxi = -1;
	for(ll i=0; i<g.n; ++i) {
		if(g.maxLength[i] == -1) g.calcMaxLength(i);
		maxi = max(maxi, g.maxLength[i]);
	}
	cout << maxi << "\n";
}