#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX = 4e5+1;
const ll MOD = 998244353;

vector<ll> p2(MAX);

void solve() {
    ll n; cin >> n;
    vector<ll> v(n);
    for (ll i=0; i<n; ++i) cin >> v[i];

    ll sum=0, minim = 0, ans = 0, nonneg=0;
    for (ll i=0; i<n; ++i) sum += v[i], minim = min(minim, sum);

    if (!minim) {
        cout << p2[n] << "\n";
        return;
    }

    sum = 0;
    for (ll i=0; i<n; ++i) {
        sum += v[i];
        if (sum == minim) ans = (ans + p2[n-i-1+nonneg]) % MOD;
        if (sum >= 0) nonneg++;
    }
    cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    p2[0] = 1;
    for (ll i=1; i<MAX; ++i) p2[i] = (p2[i-1]*2) % MOD;
    
    ll t; cin >> t;
    while(t--) solve();
}