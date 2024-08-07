#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll ;
#define REP(n) for(ll i = 0 ; i<n ;i++)

ll modular(ll a , ll b , ll m){
    if(b == 0) return 1;
    ll u = modular(a,b/2,m)%m;
    u = (u*u)%m;
    if(b%2 == 1) u = (u*a)%m;
    return u ;
}

// This is a O(n) approach try to reduce it and as n can range to 10^12 it is not efficient 
// To modify it we can obeserve a pattern that much the occurence repeat
ll SumOf_Divisiors(ll n){
    // q denotes the number of time "i" occur as a divisor .
    const ll mod = 1000000007 ;
    ll sum = 0 , q = 0 , i= 1 ;
    vector<pair<ll,ll>> v ;
    while(q!=1) {
        q = n/i ;
        pair<ll,ll> p = {q,i} ;
        v.push_back(p) ;
        i = (n/q) + 1 ;    
    }
    // Now from the above vector we would be caluclating the sum of divisors 

    ll modInv = modular(2,mod-2,mod) ;

    for( ll k = 0 ; k<v.size() - 1  ; k++){
        ll start = v[k].second, end = v[k+1].second ;
        ll temp = (((end-start)%mod*((end%mod)+(start%mod)-1)%mod)%mod * modInv)%mod ;
      
        sum = (sum + ((temp)*v[k].first)) %mod ;
    }

    ll x = v[v.size()-1].second ;

    ll temp =  ( (x%mod+n%mod)%mod * ((n-x+1)%mod)%mod  * modInv ) % mod ;
    
    
    sum = (sum + ((temp)*(v[v.size()-1].first))) %mod ;

    return sum ;

}

int main(){
    
    ll n ;
    cin >> n; 

    cout << SumOf_Divisiors(n);

    return 0 ;

}


