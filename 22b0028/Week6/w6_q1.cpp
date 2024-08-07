#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct Pair {
    int n;
    int r;

    Pair(int n, int r) : n(n), r(r) {}

    bool operator<(const Pair &p2) const {
        return r < p2.r;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, g;
    cin >> n >> m >> g;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    priority_queue<Pair> pq;
    vector<bool> guarded(n + 1, false);
    vector<int> range(n + 1, 0);

    for (int i = 0; i < g; ++i) {
        int u, v;
        cin >> u >> v;
        pq.emplace(u, v);
        guarded[u] = true;
        range[u] = v;
    }

    while (!pq.empty()) {
        Pair curr = pq.top();
        pq.pop();

        if (curr.r < range[curr.n]) continue;

        for (int neighbor : graph[curr.n]) {
            guarded[neighbor] = true;
            if (curr.r - 1 > 0 && range[neighbor] < curr.r - 1) {
                range[neighbor] = curr.r - 1;
                pq.emplace(neighbor, curr.r - 1);
            }
        }
    }

    string result;
    int counter = 0;
    for (int i = 1; i <= n; ++i) {
        if (guarded[i]) {
            result += to_string(i) + " ";
            ++counter;
        }
    }

    cout << counter << "\n" << result << "\n";

    return 0;
}
