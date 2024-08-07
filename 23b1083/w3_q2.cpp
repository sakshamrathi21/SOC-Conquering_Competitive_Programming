/**
 *    Author: Jigyasa Chouhan
 *    Created: Mon Jun 17 00:01:21 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pb push_back


bool valid(ll x, ll* k, ll n, ll t){
    ll sum = 0;
        for(ll i=0; i<n; i++){
            sum = sum + (x)/k[i];
        }
        return (sum>=t);
}

int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,t;
    cin>>n>>t;
    // cout<<"hi";
    ll k[n];
    for(ll i=0; i<n; i++){
        ll g; cin>>g;
        k[i] = g;
    }
    // cout<<"before sorting\n";
    sort(k, k+n);
    // cout<<"after sorting\n";
    ll maxposs = t*k[0];
    ll x = -1;
    for (ll b = maxposs; b >= 1; b /= 2) {
        // cout<<"for\n";
        while (!valid(x+b, k, n, t)) {
            // cout<<"While\n";
            x += b; 
        }
    }
    ll ans = x+1;
    cout<<ans<<endl;
}

