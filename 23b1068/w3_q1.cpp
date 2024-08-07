#include<bits/stdc++.h>
using namespace std;typedef int64_t ll;typedef vector<ll> vll;typedef pair<ll,ll> pll;
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define sz size
#define reach cout<<"Reached"<<endl;
#define o1(a) cout<<a<<"\n"
#define o2(a,b) cout << a << ' ' << b << "\n";
#define iArray(a,n) for(ll i=0; i<n; i++) cin >> a[i];
#define i2(a,b) cin >> a >> b;

void sol(){
    ll n;
    cin >> n;
    pair<ll,ll> a[n];
    for(ll i = 0; i < n; i++) {
        i2(a[i].ff,a[i].ss);
    }
    sort(a,a+n);
    ll time=0,reward=0;
    for(ll i = 0; i < n; i++) {
        time += a[i].ff;
        reward += a[i].ss - time;
    }
    o1(reward);
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
