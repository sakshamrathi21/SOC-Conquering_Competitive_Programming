#include<iostream>
#include<algorithm> 
#define ll long long int
using namespace std;

int main(){
    ll N, W;
    cin >> N >> W;
    ll w[N], v[N];
    for(ll i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }
    
    ll dp[N+1][W+1];
    
    for(ll i = 0; i <= N; i++){
        for(ll j = 0; j <= W; j++){
            dp[i][j] = 0;
        }
    }
    
    for(ll j = 1; j <= N; j++){
        for(ll k = 0; k <= W; k++){
            if(w[j-1] > k){ 
                dp[j][k] = dp[j-1][k];
            } else {
                dp[j][k] = max(dp[j-1][k], dp[j-1][k-w[j-1]] + v[j-1]); 
            }
        }
    }
    
    cout << dp[N][W];
    return 0;
}
