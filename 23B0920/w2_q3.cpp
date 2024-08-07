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

tuple<ll,ll,int> twosum_pos(vector<pair<ll,ll>> v,ll target, ll i){
    auto c=v.begin()+i+1;
    auto d=v.end()-1;
    bool f=true;
    
    while(c<d){
        if((*c).first+(*d).first==target){
            
            f=false;
            return {c->second,d->second,1};
        }
        else if(c->first+d->first<target){
            c++;
            
        }
        else{
            d--;
            
        }
    }

    if(f==true){
        return {0,0,-1};
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,x; cin>>n>>x;

    vector<pair<ll,ll>> v(n);

    for(ll i=0; i<n ;i++){
        ll a;cin>>a;
        v[i]={a,i};
    }
    sort(v.begin(),v.end());
    bool s=false;
    for(int i=0; i<n; i++){
        ll target=x-v[i].first;
        tuple<ll,ll,ll> j=twosum_pos(v,target,i);
        if(get<2>(j)==1){
            cout<<v[i].second+1<<" "<<get<0>(j)+1<<" "<<get<1>(j)+1;
            s=true;
            break;
        }
        else if(get<2>(j)==-1){
            
            continue;

        }
    
    }
    if(s==false){
        cout<<"IMPOSSIBLE";
    }
}