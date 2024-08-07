/**
 *    Author: Jigyasa Chouhan
 *    Created: Tue Jun 18 19:59:20 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pb push_back


int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    string b;
    // cout<<"wtf\n";
    cin>>a; 
    cin>>b; 
    // cout<<"Hi\n";
    int n = a.length();
    int m = b.length();
    // cout<<"what\n";
    vector<vector<int> > distance(n+1, vector<int>(m+1,0));
    for(int j=0; j<=m; j++){
        distance[0][j] = j;
    }
    for(int i=0; i<=n; i++){
        distance[i][0] = i;
    }
    // cout<<distance[0][0]<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1]) distance[i][j] = distance[i - 1][j - 1];
            else distance[i][j] = 1 + min(min(distance[i][j - 1], distance[i - 1][j]), distance[i - 1][j - 1]);
        }
    }
    cout<<distance[n][m]<<"\n";
}

