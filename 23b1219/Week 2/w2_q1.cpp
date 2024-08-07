#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vll s;
    for (ll i = 0; i < n; i++){
        ll x;
        cin>>x;
        s.push_back(x);
    }
    ll start=0, ans=0;
    map<ll, ll> m;
    for (ll end=0; end<n; end++) {
        if (m.find(s[end])==m.end()){
            m[s[end]]=end;
        }
        else {
            if (m[s[end]]>=start){
                start=m[s[end]]+1;
            }
            m[s[end]]=end;
        }
        ans=max(ans, end-start+1);
    }
    cout<<ans<<"\n";
}