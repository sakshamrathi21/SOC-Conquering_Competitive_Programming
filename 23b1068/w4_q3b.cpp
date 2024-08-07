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
ll maxn = 1e6;

ll expo(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll temp = expo(a, b / 2);
    ll ans = (temp * temp) % MOD;

    if (b % 2 == 0) {
        return ans;
    } else {
        return (ans * a) % MOD;
    }
}

void sol() {

}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < t; i++) {
        pair<ll, ll> p;
        i2(p.ff, p.ss);
        v.pb(p);
    }

    vector<ll> fac(maxn + 1);

    fac[0] = 1;
    for (ll i = 1; i <= maxn; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    ll invOfMax = expo(fac[maxn], MOD - 2);  // Corrected: Inverse of fac[maxn]
    vll inv(maxn + 1);
    inv[maxn] = invOfMax;
    for (ll i = maxn - 1; i >= 1; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
    inv[0] = 1;

    for (ll i = 0; i < t; i++) {
        ll n = v[i].ff, k = v[i].ss;
        if (k > n) {
            o1(0);
        } else {
            ll ans = (fac[n] * inv[k] % MOD) * inv[n - k] % MOD;
            o1(ans);
        }
    }
}
