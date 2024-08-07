#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define endl '\n'
 
const ll mod = 1000000007;
int n,m;
char grid[1001][1001];
int visited[1001][1001];
 
void dfs(int i,int j){
    stack < pair<int,int> > s;
    s.push({i,j});
    while (!s.empty()){
        pair<int,int> u = s.top();
        s.pop();
        int x = u.first; int y = u.second;
        if (x+1<n && visited[x+1][y]==0 && grid[x+1][y]=='.' ){
            visited[x+1][y]=1;
            s.push({x+1,y});
        }
        if (x-1>=0 && visited[x-1][y]==0 && grid[x-1][y]=='.' ){
            visited[x-1][y]=1;
            s.push({x-1,y});
        }
        if (y-1>=0 && visited[x][y-1]==0 && grid[x][y-1]=='.' ){
            s.push({x,y-1});
            visited[x][y-1]=1;
        }
        if (y+1<m && visited[x][y+1]==0 && grid[x][y+1]=='.' ){
            s.push({x,y+1});
            visited[x][y+1]=1;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=0;
            cin>>grid[i][j];
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (grid[i][j]=='.' && visited[i][j]==0){
                count++;
                dfs(i,j);
            }
        }
    }
    cout<<count<<endl;
    return 0;
}