#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin>>s1>>s2;
    ll a=s1.size();
    ll b=s2.size();
    vvll dp((a+1), vll(b+1));
    dp[0][0]=0;
    for(ll i=1; i<(a+1); i++) dp[i][0]=i;
    for(ll j=1; j<(b+1); j++) dp[0][j]=j;
    for(ll i=1; i<(a+1); i++){
        for(ll j=1; j<(b+1); j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
        }
    }
    cout<<dp[a][b]<<"\n";
}