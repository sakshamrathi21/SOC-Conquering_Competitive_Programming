#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<set<int>> g(n);
    vector<set<int>> neighbours(n);
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
        g[i].insert(a[i]);
        g[a[i]].insert(i);
    }
    for (int i = 0; i < n; ++i) {
        d[i] = g[i].size();
    }
    int bamboos = 0, cycles = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            vector<int> component = {i};
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                        component.push_back(v);
                    }
                }
            }
            bool bamboo = false;
            for (int j: component) {
                if (d[j] == 1) {
                    bamboo = true;
                    break;
                }
            }
            if (bamboo) {
                bamboos++;
            } else {
                cycles++;
            }
        }
    }
    cout << cycles + min(bamboos, 1) << ' ' << cycles + bamboos << '\n';
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
}