#include<bits/stdc++.h>
using namespace std;

int editDistance(string a , string b){
    int n = a.size() , m = b.size() , x;
    int dis[n+1][m+1] ;
    dis[0][0] = 0;
    for(int i = 1 ; i <= n ; i++) dis[i][0] = i ;
    for(int j = 1 ; j <= m ; j++) dis[0][j] = j ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j<=m ; j++){
            a[i-1] == b[j-1] ? x = 0 : x = 1 ; 
            dis[i][j] = min(dis[i-1][j-1] + x , min(dis[i-1][j] + 1 , dis[i][j-1] + 1)) ;
        }
    }
    return dis[n][m] ;
}

int main(){
    string a , b ;
    getline(cin,a) ;
    getline(cin,b) ;
    cout << editDistance(a,b) ;
}