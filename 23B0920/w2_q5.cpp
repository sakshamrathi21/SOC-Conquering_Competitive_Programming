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
    ll n; cin>>n;
    vector<ll> v(n);
    f1{cin>>v[i];}
    sort(v.begin(),v.end());
    ll a=v[n/2];
    ll ans=0;
    
    for(auto b:v){
        ans+=abs(a-b);
    }
    cout<<ans;
    


}