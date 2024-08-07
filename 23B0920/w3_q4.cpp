#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include<utility>
#define ll long long int
#define f(n) for(ll i=0; i<n; i++)
#define reach cout<<"reached"<<endl
#define s(v,n) for(ll i=0; i<n; i++){cin>>v[i];}
#define sp(v,n) for(ll i=0; i<n; i++){cin>>v[i].first>>v[i].second;}
#define p(a,n) for(ll i=0; i<n; i++){cout<<a[i]<<' ';}
using namespace std;



int cost(string x, string y, int p,int q){
    // cout<<"reached cost"<<endl;
    if (x[p]==y[q]) return 0;
    else return 1;
}
// int edit_distance(string x, string y, int a,int b, vector<vector<int>> &d,vector<vector<bool>> w ){
    
//     if(w[a][b]==true) {/*cout<<"reached if "<<endl;*/return d[a][b];}
//     else{
//         // cout<<"reached else "<<endl;
//         int res = min({edit_distance(x,y,a,b-1,d,w)+1,edit_distance(x,y,a-1,b,d,w)+1,edit_distance(x,y,a-1,b-1,d,w)+cost(x,y,a-1,b-1)});
//         w[a][b]=true;
//         d[a][b]=res;
//         return res;
//     }
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string x,y; cin>>x>>y;
    int a=x.size();
    int b=y.size();

    vector<vector<int>> d(a+1,vector<int> (b+1,0));
    // vector<vector<bool>> w(a+1,vector<bool> (b+1,false));

    // d[0][0]=0;
    for(int i=0 ;i<a+1; i++){
        // reach;
        
        d[i][0]=i;
        // w[i][0]=true;
    }
    for(int i=0; i<b+1; i++){
        d[0][i]=i;
        // w[0][i]=true;
    }
    for(int i=1; i<=a; i++ ){
        for(int j=1; j<=b; j++){
            if(x[i-1]==y[j-1]){
                d[i][j]=d[i-1][j-1];
            }
            else{
            d[i][j]=min({d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]+1});
            }
        }
    }
    cout<<d[a][b];
    // cout<<d[3][4];
    // cout<<edit_distance(x,y,a,b,d,w)<<endl;;
    // cout<<d[a][b]<<endl;





}