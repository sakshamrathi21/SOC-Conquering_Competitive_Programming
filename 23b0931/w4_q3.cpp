#include<bits/stdc++.h>
using namespace std;


typedef long long ll ;


ll expMod(ll a, ll b ,ll mod){
    if(b==0) return 1 ;
    ll u = expMod(a,b/2,mod)%mod ;
    u = (u*u)%mod ;
    if(b%2 == 1) u = (u*a)%mod ;
    return u ;
}

ll modInv(ll a , ll mod){
    return expMod(a,mod-2,mod) ;
}

// n!/(r!)(n-r)! = (n/n-r)*(n-1/n-r-1)*...(r+1/1) // n-r terms
// n = 100000000 * 10000000000
ll binomialCoeff(ll n , ll r){
    const ll mod = 1000000007 ;
    ll num = 1 , den = 1 ;
    for(ll t1 = 0 ; t1 < n-r ; t1++) {
        num = (num*(n-t1))%mod ;
        den = (den*(n-r-t1))%mod ;
    }
    return (num*modInv(den,mod))%mod ;
}

int main(){
    ll n ;
    cin >> n ;
    vector<ll> res(n) ;
    for(ll i = 0 ; i< n ; i++){
        ll a, b;
        cin >> a >> b ;
        res[i] = binomialCoeff(a,b);
    }
    for(auto x : res) cout << x << endl ;
    return 0 ;
}

