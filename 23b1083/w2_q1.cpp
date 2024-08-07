
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
  ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin >> a[i];
    map<ll,ll> mp;
    ll ans = 0;
    ll L=0,R=0;
    while(R<n){
        if(mp.find(a[R])!=mp.end()&&mp[a[R]]>=L){
 
            L=max(L,mp[a[R]]+1);
        }   
        mp[a[R]]=R;
        ans=max(ans,R-L+1);
       R++;
    }
    cout<<ans<<endl;
  return 0;
}

