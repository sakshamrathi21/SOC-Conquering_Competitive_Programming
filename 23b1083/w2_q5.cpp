
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll med = a[n/2];
    ll ans=0;
    for(ll i=0; i<n; i++) ans+=abs(a[i]-med);
    cout<<ans;
    
}
