#include <bits/stdc++.h>
using namespace std;

#define rp(n) for(decltype(n) i=0; i<n; i++)
#define rpv(n, j) for(decltype(n) j=0; j<n; j++)
#define ll long long int
typedef vector<ll> vll;
#define o1(a) cout << a << endl;
#define mod 1000000007

vector<vector<int>> adj;
vector<int> indegree;
vector<ll> dp;

void topological_sort(int n, vector<int>& order) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (auto v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    indegree.resize(n + 1, 0);
    dp.resize(n + 1, 0);

    rp(m) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y]++;
    }

    vector<int> order;
    topological_sort(n, order);

    dp[1] = 1; // Start from node 1
    for (auto u : order) {
        for (auto v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % mod;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
