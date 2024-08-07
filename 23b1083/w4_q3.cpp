/**
 *    Author: Jigyasa Chouhan
 *    Created: Fri Jul  5 17:32:31 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pb push_back
const ll N = 1000000007;

ll powmod(ll x, ll n, ll m){
    if(n==0) return 1;
    ll half = n/2;
    ll u = powmod(x, half, m);
    u = (u*u)%m;
    if(n%2) u = (u*x)%m;
    return u; 
}

int modInverse(int a) {
    return powmod(a, N-2, N);
}


int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    ll t; cin>>t;
    ll maxn = 1000000;
    ll fact[maxn+1];
    fact[0] = 1;
    for(ll i=1; i<=maxn; i++){
        fact[i] = (fact[i-1]*i)%N;
    }
    while(t--){
        ll a,b; cin>>a>>b;
        ll ans = (fact[a]*modInverse(fact[b]))%N;
        ans = (ans*modInverse(fact[a-b]))%N;
        cout<<ans<<endl;
    }
    
}

