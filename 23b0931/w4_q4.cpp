#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;

const ll mod = 1000000007 ;

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

vector<ll> factorial(ll n){
    vector<ll> v(n+1,1);
    for(int i = 1 ; i <=n ; i++) v[i] = (i%mod*v[i-1])%mod ;
    return v ; 
}


ll binomialCoeff(ll n ,ll r , vector<ll> & fac){
    return ((fac[n]) * modInv(((fac[n-r]*fac[r])%mod) , mod) )%mod ;
}

int main(){
    ll t , a , b , maxi = 0;
    cin >> t ;
    vector<vector<ll>> input ;
    while(t--){
        cin >> a >> b ;
        input.push_back({a,b}) ;
        maxi = max(a,maxi) ;
    }
    vector<ll> fac = factorial(maxi) ; 
    for(auto x : input) cout << binomialCoeff(x[0],x[1],fac) << endl ;
    return 0;
}