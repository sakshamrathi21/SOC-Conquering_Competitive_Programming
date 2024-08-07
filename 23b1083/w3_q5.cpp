/**
 *    Author: Jigyasa Chouhan
 *    Created: Fri Jun 21 12:22:36 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll a[n+1], b[n+1];
        ll N = pow(10,9) + 7;
        a[0] = 0;
        b[0] = 0;
        a[1] = 1;
        b[1] = 1;
        for(ll i=2; i<=n; i++){
            a[i] = 2*a[i-1] + b[i-1];
            a[i] = a[i] % N;
            b[i] = 4*b[i-1] + a[i-1];
            b[i] = b[i] % N;
        }
        cout<<(a[n]+b[n])%N<<"\n";
    }
}

