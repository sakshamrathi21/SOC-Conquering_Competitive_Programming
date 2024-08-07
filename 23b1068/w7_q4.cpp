#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define sz size
#define reach cout << "Reached" << endl;
#define o1(a) cout << a << "\n"
#define o2(a, b) cout << a << ' ' << b << "\n";
#define iArray(a, n) for (ll i = 0; i < n; i++) cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1000007;



void sol(){
    string s;
    cin >> s;
    ll n = s.size();
    ll base = 69420;
    vll dp(n,0);
    vll base_pow(n);
    base_pow[0] = 1;
    for(ll i = 1; i < n; i++) {
        base_pow[i] = base*base_pow[i-1]%MOD;
    }
    vll hash(n);
    hash[0] = s[0];
    for(ll i = 1; i < n; i++) {
        hash[i] = (hash[i-1]*base%MOD +s[i])%MOD;
    }
    dp[n-1] = 1;
    for(ll i = n-2; i >= 0; i--) {
        ll len = min(i+1,n-1-i);
        if(2*i+1>=n || dp[2*i+1]==1){
        ll hash1 = hash[len-1];
        ll hash2 = (hash[i+len] - hash[i]*base_pow[len]%MOD)%MOD;
        //o2(hash1,hash2);
        if(hash2<0) hash2 += MOD;
        if(hash1 == hash2) dp[i] = 1;
        }

    }
    for(ll i = 0; i < n; i++) {
        if(dp[i]==1){
            cout << i+1 << ' '; 
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
