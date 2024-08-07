#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

bool found = false;
vector<int> path;
vector<bool> vis;
int cycleStart = -1;
int cycleEnd = -1;

void cycleUtil(vector<vector<int>>& graph, int curr, int par) {
    vis[curr] = true;

    for (int j : graph[curr]) {
        if (j == par) continue;
        if (vis[j]) {
            found = true;
            cycleStart = j;
            cycleEnd = curr;
            return;
        }
        path[j] = curr;
        cycleUtil(graph, j, curr);
        if (found) return;
    }
}

void cycle(vector<vector<int>>& graph) {
    for (int i = 1; i < (int)graph.size(); i++) {
        if (!vis[i]) {
            cycleUtil(graph, i, -1);
            if (found) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    path.resize(n + 1);
    vis.resize(n + 1);

    for (int i = 0; i <= n; i++) {
        graph[i] = vector<int>();
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cycle(graph);

    if (!found) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> list;
        list.push_back(cycleStart);

        while (cycleEnd != cycleStart) {
            list.push_back(cycleEnd);
            cycleEnd = path[cycleEnd];
        }

        list.push_back(cycleStart);

        cout << list.size() << "\n";
        for (int i = 0; i < (int)list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
