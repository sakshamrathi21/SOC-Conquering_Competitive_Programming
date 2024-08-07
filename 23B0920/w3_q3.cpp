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
#define reach cout<<"reached";
#define s(v,n) for(ll i=0; i<n; i++){cin>>v[i];}
#define sp(v,n) for(ll i=0; i<n; i++){cin>>v[i].first>>v[i].second;}
#define p(a,n) for(ll i=0; i<n; i++){cout<<a[i]<<' ';}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin>>n;

    ll m=1e9+7;
    vector<ll> res(n+1,0);
    res[0]=1;
    for(int x=1; x<=n; x++){
        for(int i=1; i<=6; i++){
            if(x-i>=0) {
                res[x]+=res[x-i];
                res[x]%=m;
                }
            res[x]%=m;
        }
    }
    cout<<res[n];

}