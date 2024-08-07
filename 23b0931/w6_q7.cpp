#include <bits/stdc++.h>
using namespace std;

// Depth-first search function to calculate the distance of
// each node from a given node
void dfs(int parent, int node, int dist, int c,
         vector<int> adj[], vector<vector<int> >& dp)
{
    // Store the distance of the node from the starting node
    dp[node][c] = dist;

    // Iterate over all the adjacent nodes
    for (auto child : adj[node])
        // If the adjacent node is not the parent
        if (child != parent)
            // Recursively call for the child node and
            // increase the distance by 1
            dfs(node, child, dist + 1, c, adj, dp);
}

// Breadth-first search function to find the node at the
// maximum distance from a given node
int bfs(int node, int n, vector<int> adj[])
{
    // Queue to store the node and its distance from the
    // starting node
    queue<pair<int, int> > q;

    // Push the starting node into the queue with distance 0
    q.push({ node, 0 });

    // Visited array to keep track of visited nodes
    vector<bool> vis(n + 1, false);

    // Mark the starting node as visited
    vis[node] = true;

    int u, dist;
    while (!q.empty()) {
        // Node at the front of the queue
        u = q.front().first;
        // Distance of the node from the starting node
        dist = q.front().second;
        // Remove the node from the queue
        q.pop();

        // Iterate over all the adjacent nodes
        for (auto child : adj[u]) {
            if (!vis[child]) {
                // Push the node into the queue
                q.push({ child, dist + 1 });
                // Mark the node as visited
                vis[child] = true;
            }
        }
    }
    // Return the node at the maximum distance
    return u;
}

vector<int> treedistance1(int n, vector<vector<int> >& v)
{
    vector<int> adj[n + 1];
    for (auto i : v) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<int> mxdist;
    // Node at the maximum distance from node 1
    int di_st = bfs(1, n, adj);

    // Node at the maximum distance from node di_st
    int di_end = bfs(di_st, n, adj);

    // 2D vector to store the maximum distance of each node
    vector<vector<int> > dp(n + 1, vector<int>(2, 0));

    // DFS from di_st
    dfs(0, di_st, 0, 0, adj, dp);
    // DFS from di_end
    dfs(0, di_end, 0, 1, adj, dp);

    // Take the max distance
    for (int i = 1; i <= n; i++)
        mxdist.push_back(max(dp[i][0], dp[i][1]));

    return mxdist;
}


int main()
{
    int n = 5;
    vector<vector<int> > v
        = { { 1, 2 }, { 1, 3 }, { 3, 4 }, { 3, 5 } };

    vector<int> mxdist = treedistance1(n, v);
      if( n == 1 ){
        cout<<0<<endl;
    }
    for (auto i : mxdist)
        cout << i << " ";
    return 0;
}