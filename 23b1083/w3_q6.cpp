/**
 *    Author: Jigyasa Chouhan
 *    Created: Wed Jun 19 22:45:15 IST 2024
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
    ll n, w; cin>>n>>w;
    ll weights[n], values[n];
    for(ll i=0; i<n; i++) cin>>weights[i]>>values[i];
    // vector<vll > dp (n+1, vll(w+1, 0));
    // for(ll i=1; i<=n; i++){
    //     for(ll j=1; j<=w; j++){
    //         if(weights[i-1]<=j) dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
    //         else dp[i][j] = dp[i-1][j];
    //     }
    // }
    // cout<<dp[n][w]<<endl;
    vector<vector<ll> > dp(n+1, vector<ll>(100005, INT32_MAX));
    for (ll i= 0 ; i <= n ; i ++) dp[i][0] = 0;
    for(ll i=1; i<=n; i++){
        for(ll v=1; v<=100004; v++){
            if(v>=values[i-1]) dp[i][v] = min(dp[i-1][v], weights[i-1] + dp[i-1][v-values[i-1]]);
            else dp[i][v] = dp[i-1][v];
        }
    }
    ll maxval = 0;
    // for(ll i=0; i<=n; i++){
    //     for(ll j=0; j<100005; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(ll i=100004; i>=0; i--){
        if(dp[n][i]<=w){
            maxval = i;
            break;
        }
    }
    cout<<maxval<<endl;
}

