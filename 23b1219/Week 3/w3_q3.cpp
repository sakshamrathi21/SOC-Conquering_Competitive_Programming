#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vll v(n+1);
    v[0]=1;
    ll m=1e9+7;
    for(ll i=1; i<n+1; i++) {
        for(ll j=1; j<=i && j<=6; j++) {
            v[i]=v[i]+(v[i-j]%m);
        }
    }
    cout<<(v[n]%m)<<"\n";
}