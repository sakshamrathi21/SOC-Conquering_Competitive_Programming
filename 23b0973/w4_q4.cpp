#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll m = 1000000007;
ll fac(ll a){
        ll x=1;
        for(ll t1=1; t1<=a; t1++){
                x *= t1;
                x %= m;
        }
        return x;
}
ll modpow(ll p, ll q){
        p = p%m;
        if(q==0) return 1;
        ll u = modpow(p,q/2);
        u = (u*u)%m;
        if(q%2 ==1) u = (u*p)%m;
        return u;
}
ll bc( ll c, ll d){
        ll num = fac(c);
        ll den = (fac(c-d)) * (fac(d));
       return (num * modpow(den,m-2))%m;
}
int main(){
        ll n,m;
        cin >> n >> m;
        cout << bc(m+n-1,m) << "\n";
}