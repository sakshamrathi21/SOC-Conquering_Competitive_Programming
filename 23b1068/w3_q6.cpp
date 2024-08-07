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
        
    ll n,w,sum=0;
    i2(n,w);
    pair<ll,ll> a[n];
    
    for(ll i = 0; i < n; i++) {
        i2(a[i].ff,a[i].ss);
        sum+=a[i].ss;
    }

    vector<ll> dp(sum+1,1e12);
    dp[0] = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j=sum; j>=a[i].ss; j--){
            dp[j] = min(dp[j],dp[j-a[i].ss]+a[i].ff);
        }
    }
    ll answer = 0;
    for (ll i = 0; i <= sum; i++) {
        if (dp[i] <= w) {
            answer = i;
        }
    }
    cout << answer << endl;
    // for(ll i = 0; i < sum+1; i++) {
    //     cout << dp[i] << ' ';
        
    // }


}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
