#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll ;

ll expMod(ll a, ll b ,ll mod){
    if(b==0) return 1 ;
    ll u = expMod(a,b/2,mod)%mod ;
    u = (u*u)%mod ;
    if(b%2 == 1) u = (u*a)%mod ;
    return u ;
}

ll modInv(ll x , ll mod){
    return expMod(x,mod-2,mod);
}

ll SumOfDivisors(map<ll,ll> primeFactor){
    const ll mod = 1000000007 ;
    ll res = 1 ;
    for(auto x : primeFactor) {
        res = (res*((((expMod(x.first,(x.second+1)%(mod-1),mod)-1))%mod)*modInv(x.first-1,mod))%mod)%mod ;
    }
    return res ; 
}

ll number(map<ll,ll> primeFactor ,ll mod){
    ll prod = 1 ;
    for(auto x : primeFactor) prod = (prod*((x.second+1)%mod))%mod ;
    return prod ;
}

ll product(map<ll,ll> primeFactor){
    const ll mod = 1000000007 ;
    ll n = number(primeFactor,mod-1) , num = 1 , res = 1;
    for(auto x : primeFactor) {
        res = (res*expMod(expMod(x.first,((x.second)*(x.second+1)/2)%(mod-1),mod),n,mod))%mod ;  
    }
    return res ;
}

int main(){
    const ll mod = 1000000007 ;
    ll n ; 
    map<ll,ll> m;
    cin >> n ;
    for(ll i = 0 ; i<n ; i++){
        ll a , b ;
        cin >> a >> b ;
        m[a] = b ;
    }
    cout << number(m,mod) <<" " << SumOfDivisors(m) << " " << product(m) << endl ; 
    return 0 ;
}