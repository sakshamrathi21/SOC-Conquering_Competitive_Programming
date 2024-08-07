#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const ll INV2 = 500000004;

// this is based on the idea that sum of all divisors till n is just
// i*(n/i) for i=1 to n. but n/i stays constant for a set thus we need
// not calculate it everytime. for example
// for i in n/2 to <n; we have n/i = 1; hence sum i*(n/i) = 1*(sum i)
// in general for i in n/k to <n/(k-1); we have n/i = k-1; hence
// sum i*(n/i) = (k-1)*(sum i). where k can be 2, 3, 4, ... n; and sum i is
// some thought is needed and we can say that it's sum[n/k+1,...,n/(k-1)] where
// integer divsion is taking place.

// calculates (k-1)*(sum i) mod MOD
ll weighted_sum(ll n, ll k) {
    ll a = (n / k + 1) % MOD; 
    ll b = (n / (k - 1)) % MOD; 
    ll n_terms = (b - a + 1 + MOD) % MOD; 
    ll sum = (n_terms * (a + b) % MOD) * INV2 % MOD; 
    ll to_add = (sum * ((k - 1) % MOD)) % MOD;
    return to_add;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> s;
    if(n==1) {
        cout << 1 << endl;
        return 0;
    }
    ll ans=n, i=2;
    for( ; i*i<=n; i++) {
        s.push_back(n/i);
        ans = (ans + weighted_sum(n, i))%MOD;
    }
    if (s[s.size()-1]+1 != i && (n/i != n/(i-1))) {
        ans = (ans + weighted_sum(n, i))%MOD;
    }
    for (int i=s.size()-1; i>=0; i--) {
        ans = (ans + weighted_sum(n,s[i]+1))%MOD;
    }
    cout << ans << endl;
}