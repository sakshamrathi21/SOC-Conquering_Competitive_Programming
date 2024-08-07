#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll m, p;
    cin>>m>>p;
    vll v(m);
    for(ll i=0; i<m; i++) cin>>v[i];
    sort(v.begin(), v.end());
    ll min=0, max=(p/m+1)*v[m-1];
    while (min!=max){
        ll mid=(min+max)/2;
        ll sum=0;
        for(ll i=0; i<m; i++) sum+=(mid/v[i]);
        if(sum>=p) max=mid;
        else min=mid+1;
    }
    cout<<max<<"\n";
}