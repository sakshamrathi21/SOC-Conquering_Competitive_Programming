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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    ll m=1e9+7;

    ll n=1e6;

        vector<ll> width_1(n+1),width_2(n+1);
        width_1[1]=1; width_2[1]=1;
        for(ll i=2; i<=n; i++){
            width_1[i]=(4*width_1[i-1]+width_2[i-1])%m;
            width_2[i]=(2*width_2[i-1]+width_1[i-1])%m;
        }

    while(t--){
        ll p; cin>>p;
        cout<<(width_1[p]+width_2[p])%m<<"\n";
        
    }

}