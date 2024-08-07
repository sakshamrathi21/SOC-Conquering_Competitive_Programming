#include<bits/stdc++.h>
using namespace std;typedef int64_t ll;typedef vector<ll> vll;typedef pair<ll,ll> pll;
#define pb push_back
#define pob pop_back
#define ff first				
#define ss second 
#define sz size	
#define reach cout<<"Reached"<<endl; 
#define o1(a) cout<<a<<"\n"
#define o2(a,b) cout << a << ' ' << b << "\n"; 
#define iArray(a,n) for(ll i=0; i<n; i++) cin >> a[i]; 
#define i2(a,b) cin >> a >> b;

void sol(){
    ll t;
    cin >> t;
    ll md = 1000000007;
    ll array[t];
    ll maxi = -1;
    for(ll i = 0; i < t; i++) {
        cin >> array[i];
        maxi = max(array[i],maxi);
    }
    

    ll dp[maxi+1][2];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(ll i = 2; i <= maxi; i++) {
        dp[i][0] = (4*dp[i-1][0]%md+dp[i-1][1])%md;
        dp[i][1] = (dp[i-1][0]+2*dp[i-1][1]%md)%md;
    }
    for(auto c:array){
        o1((dp[c][0]+dp[c][1])%md);
    }
    

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
