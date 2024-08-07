#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

const int mod = 1e9+7;

vector<vector<int>> adj(1e5+1);

map<int, int> routes;
int n, m;

int DFS(int current) {
    if (routes.find(current) != routes.end()) return routes[current];
    if (current == n) return 1;
    int count = 0;
    for (auto i : adj[current]) {
        (count += DFS(i)%mod);
    }

    return routes[current] = count%mod;
}

signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    cout << DFS(1) ;
    return 0;
}