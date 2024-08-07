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
#define f1 for(int i=0; i<n; i++)
#define p1 for(int i=0; i<n; i++){cout<<a[i]<<' ';}
#define s1 while(t--)
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll max_n=2e5;

    ll n,x; cin>>n>>x;
    vector<pair<ll,ll>> v(n);

    for(int i=0; i<n ;i++){
        ll a;cin>>a;
        v[i]={a,i};
    }
    sort(v.begin(),v.end());
    auto c=v.begin();
    auto d=v.end()-1;
    bool f=true;
    
    while(c<d){
        if((*c).first+(*d).first==x){
            
            cout<<c->second+1<<" "<<d->second+1;
            f=false;
            break;
        }
        else if(c->first+d->first<x){
            c++;
            
        }
        else{
            d--;
            
        }
    }

    if(f==true){
        cout<<"IMPOSSIBLE";
    }



}