#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);





vector<vector<int>> graph(100005, vector<int>());
int distances[100005];

int dfs(int node) {
    if (distances[node] != -1) {
        return distances[node];
    }
    int longest_path = 0;
    for (auto child : graph[node]) {
        longest_path = max(longest_path, dfs(child));
    }
    return distances[node] = 1+ longest_path;
}
int main() {
    fast_io;
    int N, M;
    cin >> N >> M;
    memset(distances, -1, sizeof distances);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    int result = 0;
    for (int i = 1; i < N+1; i++) {
        result = max(result, dfs(i));
    }
    cout << result - 1 << endl;
}