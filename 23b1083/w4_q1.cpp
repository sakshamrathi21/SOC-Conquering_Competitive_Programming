/**
 *    Author: Jigyasa Chouhan
 *    Created: Wed Jun 19 23:11:19 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pb push_back

ll powmod(ll x, ll n, ll m){
    if(n==0) return 1;
    ll half = n/2;
    ll u = powmod(x, half, m);
    u = (u*u)%m;
    if(n%2) u = (u*x)%m;
    return u; 
}


int main(){
    ll N = pow(10,9) + 7;
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin>>n;
    while(n--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll brem = powmod(b, c, N-1);
        ll arem = powmod(a, brem, N);
        cout<<arem<<endl;
        
    }
}

