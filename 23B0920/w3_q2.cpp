#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#include<utility>
#define reach cout<<"reached"<<endl

#define ll long long int
#define f(n) for(ll i=0; i<n; i++)
#define s(v,n) for(ll i=0; i<n; i++){cin>>v[i];}
#define sp(v,n) for(ll i=0; i<n; i++){cin>>v[i].first>>v[i].second;}
#define p(a,n) for(ll i=0; i<n; i++){cout<<a[i]<<' ';}
using namespace std;

bool bound(ll x, ll t, ll n, vector<ll> v){
    ll ans=0;
    f(n){
        ans+=x/v[i];
    }
    // cout<<ans<<" "<<"hi"<<endl;
    return ans<t?false:true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,t; cin>>n>>t;
    vector<ll> v(n);
    s(v,n);
    
    ll z=*min_element(v.begin(),v.end())*t;
    // cout<<z<<endl;
    // binary search

    ll x = -1;
    for(ll b=z; b>=1; b/=2){
        while(!bound(x+b,t,n,v)) {x+=b;}
        // cout<<x<<" "<<b<<endl;
    }
    // cout<<bound((5e17)-1,1e9,100,v)<<" "<<"hello";
    ll ans=x+1;
    cout<<ans;


}