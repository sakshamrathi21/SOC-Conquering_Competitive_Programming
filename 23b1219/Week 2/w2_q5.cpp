#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vll v;
    ll n;
    cin>>n;
    for (ll i=0; i<n; i++){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    if(n%2==1){
        ll mid=v[n/2];
        ll mini=0;
        for(ll i=0; i<n; i++){
            mini+=abs(v[i]-mid);
        }
        cout<<mini<<"\n";
    }
    else{
        ll mid1=v[n/2-1];
        ll mid2=v[n/2];
        ll mini1=0, mini2=0;
        for(ll i=0; i<n; i++){
            mini1+=abs(v[i]-mid1);
            mini2+=abs(v[i]-mid2);
        }
        ll mini=min(mini1, mini2);
        cout<<mini<<"\n";
    }
}