#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const ll TOT_MOD_1 = 5e8+2;

ll fast_pow(ll a, ll b, ll mod, ll tot) {
    if(a==0 && b==0) return 1;
    if(a == 0) return 0;
    if(b == 0) return 1;
    b %= tot;
    a %= mod;
    ll ans = 1;
    while (b > 0) {
        if (b%2 == 1) {
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    for (ll i=0; i<n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll b_pow_c = fast_pow(b, c, MOD-1, TOT_MOD_1);
        cout << fast_pow(a, b_pow_c, MOD, MOD-1) << "\n";
    }
}