/**
 *    Author: Jigyasa Chouhan
 *    Created: Mon Jul  8 01:18:31 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pb push_back
ll N = pow(10,9) + 7;

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
    ll n, m; cin>>n>>m;
    ll ans = 1;
    ll a = m+n-1;
    ll b = n-1;
    for(ll i=b+1; i<=a; i++){
        ans = (ans*(i%N))%N;
    }
    for(ll i=1; i<=a-b; i++){
        ans = (ans*modInverse(i))%N;
    }
    cout<<ans<<endl;
}

