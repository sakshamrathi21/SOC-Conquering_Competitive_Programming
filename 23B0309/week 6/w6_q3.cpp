
#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<int> &top_sort, bool *visited, vector<int> neighbours[])
{
    if (visited[v] == false)
    {
        visited[v] = true;
        for (auto neighbour : neighbours[v])
        {
            dfs(neighbour, top_sort, visited, neighbours);
        }
        top_sort.push_back(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> neighbours[n];
    vector<int> predecessors[n];
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        neighbours[v1 - 1].push_back(v2 - 1);
        predecessors[v2 - 1].push_back(v1 - 1);
    }

    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<int> top_sort;
    dfs(0, top_sort, visited, neighbours);
    long long dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 0;
    }
    long long mo = 1000000007;
    while (top_sort.size() > 0)
    {
        int currentv = top_sort.back();
        top_sort.pop_back();
        dp[currentv] = 0;
        dp[0] = 1;
        for (auto v : predecessors[currentv])
        {
            dp[currentv] += (dp[v] % mo);
            dp[currentv] = dp[currentv] % mo;
        }
    }
    cout << dp[n - 1];
}
