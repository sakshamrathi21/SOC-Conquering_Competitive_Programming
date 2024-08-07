#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll modpow(ll p, ll q, ll r){
        p = p%r;
        if(q==0) return 1%r;
        ll u = modpow(p,q/2,r);
        u = (u*u)%r;
        if(q%2 ==1) u = (u*p)%r;
        return u;
}
int main(){
        ll n;
        cin >> n;
        vector<ll> a,b,c;
        for(ll i=0;i<n;i++){
                ll t1,t2,t3;
                cin >> t1 >> t2 >> t3;
                a.push_back(t1);
                b.push_back(t2);
                c.push_back(t3);
        }
        ll m = 1000000007;
        for(ll j=0;j<n;j++){
                ll s;
                s = modpow(b[j],c[j],m-1);
                ll t = modpow(a[j],s,m);
                cout << t << "\n";
        }
}