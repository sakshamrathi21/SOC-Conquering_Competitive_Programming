#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vll v;
    for(ll i=0; i<n; i++) {
        ll x;
        cin>>x;
        v.push_back(x);
    }
    ll m=1e9 + 7;
    ll p=*max_element(v.begin(), v.end());
    vll a(p), b(p);
    a[0]=b[0]=1;
    for(ll i=1; i<p; i++) {
        a[i] = (a[i-1]%m)*2+(b[i-1]%m);
        a[i]%=m;
        b[i] = (b[i-1]%m)*4+(a[i-1]%m);
        b[i]%=m;
    }
    for(auto x: v) {
        cout<<(a[x-1]+b[x-1])%m<<"\n";
    }

}