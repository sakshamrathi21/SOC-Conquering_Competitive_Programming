
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>

int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x; cin>>n>>x;
    vll a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    map<ll, ll> mp;
    for(ll i=0; i<n; i++){
        if(mp.find(x-a[i])!=mp.end()){
            cout<<mp[x-a[i]]+1<<" "<<i+1;
            return 0;
        }
        mp[a[i]]=i;
    }
cout<<"IMPOSSIBLE\n";
    
}
