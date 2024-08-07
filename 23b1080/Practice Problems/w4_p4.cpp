#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

ll power(ll x, ll y, ll m) {
    if (y==0) return 1;
    ll ans=1;
    x %= m;
    while(y) {
        if (y&1) ans = (ans*x)%m;
        y >>= 1;
        x = (x*x)%m;
    }
    return ans;
}

ll num(ll m, ll n) {
    ll sum=0;
    for (ll i=0; i<n; i++) {
        ll gcd_val = __gcd(i, n);
        sum = (sum+power(m, gcd_val, MOD))%MOD;
    }
    ll n_inv = power(n, MOD-2, MOD);
    sum = (sum*n_inv)%MOD;
    return sum;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll m, n;
    cin >> n >> m;
    cout << num(m, n) << "\n";
}