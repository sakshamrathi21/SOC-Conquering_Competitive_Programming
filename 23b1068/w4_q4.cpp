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

ll fac(ll n) {
    ll ans = 1;
    for (ll i = 2; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    return ans;
}

ll expo(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll temp = expo(a, b / 2);
    ll ans = (temp * temp) % MOD;
    if (b % 2 == 0) return ans;
    else return (ans * a) % MOD;
}

void sol() {
    ll n, k;
    i2(n, k);
    
    // Binomial coefficient C(n + k - 1, k)
    ll fac_nk_1 = fac(n + k - 1);
    ll fac_k = fac(k);
    ll fac_n_1 = fac(n - 1);
    
    ll inv_fac_k = expo(fac_k, MOD - 2);
    ll inv_fac_n_1 = expo(fac_n_1, MOD - 2);
    
    ll out = (fac_nk_1 * inv_fac_k % MOD) * inv_fac_n_1 % MOD;
    o1(out);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
