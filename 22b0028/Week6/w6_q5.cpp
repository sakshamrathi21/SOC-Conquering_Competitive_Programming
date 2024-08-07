#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

class Pair {
public:
    int n;
    int len;
    Pair(int n, int len) : n(n), len(len) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indeg(n + 1, 0);

    int u, v;
    while (m-- > 0) {
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
    }

    queue<Pair> q;
    int maxLen = 0;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(Pair(i, 0));
        }
    }

    while (!q.empty()) {
        Pair curr = q.front();
        q.pop();
        maxLen = max(maxLen, curr.len);
        for (int j : graph[curr.n]) {
            if (--indeg[j] == 0) {
                q.push(Pair(j, curr.len + 1));
            }
        }
    }

    cout << maxLen << endl;

    return 0;
}
