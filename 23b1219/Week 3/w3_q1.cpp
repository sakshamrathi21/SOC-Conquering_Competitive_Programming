#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<pair<ll, ll>> v;
    for(ll i=0; i<n; i++){
        ll a, b;
        cin>>a>>b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    ll maxr=0, t=0;
    for(auto x : v) {
        t+=x.first;
        maxr+=x.second-t;
    }
    cout<<maxr<<"\n";
}