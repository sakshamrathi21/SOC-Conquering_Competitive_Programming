#include<bits/stdc++.h>
using namespace std;

void dfs(int v,bool *visited,int *dp,vector<int> successors[])
{
    if (visited[v]==false)
    {
        dp[v]=0;
        for(auto successor: successors[v])
        {
            if (dp[successor]==-1)
            {
                dfs(successor,visited,dp,successors);
            }
            dp[v]=max(dp[v],dp[successor]+1);
        }
        visited[v]=true;}}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> successors[n];
    vector<int> predecessors[n];
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        successors[v1-1].push_back(v2-1);
        predecessors[v2-1].push_back(v1-1);
    }
    bool visited[n];
    int dp[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        dp[i]=-1;
    }
    int longest_path = 0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false && predecessors[i].size()==0)
        {
            dfs(i,visited,dp,successors);
            longest_path=max(dp[i],longest_path);}}
    cout<<longest_path;
}
