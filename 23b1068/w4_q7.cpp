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

const ll MOD = 1000000007;

ll mex(const vector<ll> &v) {
    unordered_set<ll> s(v.begin(), v.end());
    ll mex_value = 0;
    while (s.count(mex_value)) {
        mex_value++;
    }
    return mex_value;
}

void sol(){
    ll n;
    cin >> n;
    ll a[n];
    ll maxi = -1;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    maxi = min((ll)2000,maxi);
    
    ll dp[maxi+1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    
    for(ll i=3; i<=maxi; i++){
        vector<ll> v;
        for(ll j=1; j<=(i-1)/2; j++){
            v.push_back(dp[j]^dp[i-j]);
            //cout << j << ' ' << i-j << endl;
            //cout << dp[j] << ' ' << dp[i-j] << endl;
        }
        
         dp[i] = mex(v);
        // for(auto c:v){
        //     cout << c << ' ';
        // }
        // cout << endl;
    }
    for(ll c:a){
        if(c>2000) o1("first");
        else if(dp[c]==0) o1("second");
        else o1("first");
    }
    
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
