#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indeg(n + 1, 0);
    vector<int> dp(n + 1, 0);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    dp[1] = 1;

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int j : graph[curr]) {
            indeg[j]--;
            if (indeg[j] == 0) {
                q.push(j);
            }
        }

        for (int j : graph[curr]) {
            dp[j] = (dp[curr] + dp[j]) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
