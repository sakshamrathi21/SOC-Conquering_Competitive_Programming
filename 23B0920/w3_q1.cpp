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
#define f(n) for(int i=0; i<n; i++)
#define sp(v,n) for(ll i=0; i<n; i++){cin>>v[i].first>>v[i].second;}
#define s(v,n) for(int i=0; i<n; i++){cin>>v[i];}
#define p(a,n) for(int i=0; i<n; i++){cout<<a[i]<<' ';}

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin>>n;
    vector<pair<ll,ll>> v(n);
    sp(v,n);
    sort(v.begin(),v.end());
    ll curr_time=0;
    ll ans=0;
    f(n){
        curr_time+=v[i].first;
        ans+=v[i].second-curr_time;
        
    }
    cout<<ans;
    

}