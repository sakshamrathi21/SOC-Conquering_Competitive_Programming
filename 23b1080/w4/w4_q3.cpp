#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// have to calculate (a, b) mod m
// we'll calulate a! mod m, b!^-1 mod m, (a-b)!^-1 mod m
// we'll use dp to store the factorials and use them easily when needed
// since a,b <= 1e6 we'll calculate factorials and inverses of them till 1e6

const ll MOD = 1e9 + 7;
const ll MAXN = 1e6;
ll fac[MAXN+1], inv[MAXN+1];

// if m is prime, x^-1 = x^(m-2) mod m, since x^(m-1) mod m = 1
// thus we need to calculate exponentiation mod m, can be done in O(log n)
// by doing x, x*x, (x*x)*(x*x), ...
// since m is prime, x^y mod m = x^(y mod (m-1)) mod m
ll power(ll x, ll y, ll m) {
    x %= m;
    y %= m-1;
    ll ans = 1;
    while(y) {
        if(y&1) ans = (ans*x)%m;
        x = (x*x)%m;
        y >>= 1;
    }
    return ans;
}

// let's calculate factorials of 0, 1, ..., 1e6
void precompute() {
    fac[0] = 1;
    for(ll i=1; i<=MAXN; i++) {
        fac[i] = (fac[i-1]*i)%MOD;
    }
    // let's calculate inverses of 0!, 1!, ..., 1e6!
    // we'll use a nice recursion, n!^-1 = (n+1)!^-1 * (n+1) mod m
    inv[MAXN] = power(fac[MAXN], MOD-2, MOD);
    for(ll i=MAXN-1; i>=0; i--) {
        inv[i] = (inv[i+1]*(i+1))%MOD;
    }
}

// now we have all factorials and inverses, thus
// (a, b) mod m = a!*b!^-1*(a-b)!^-1 mod m
ll C(ll a, ll b) {
    if(a < b) return 0;
    ll ans = (fac[a]*inv[b])%MOD;
    ans = (ans*inv[a-b])%MOD; // so that it doesn't overflow
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> queries(n);
    precompute();
    for(ll i=0; i<n; i++) {
        cin >> queries[i].first >> queries[i].second;
    }
    for(ll i=0; i<n; i++) {
        cout << C(queries[i].first, queries[i].second) << "\n";
    }
}