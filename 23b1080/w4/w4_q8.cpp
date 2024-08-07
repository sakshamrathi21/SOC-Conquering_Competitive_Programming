#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

// calculating a^b in O(log b) time
ll power(ll a, ll b,ll mod) {
    ll res = 1;
    while(b) {
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, num=1, num_mod_1=1, sum = 1, prod = 1;
    cin >> n;
    for(ll i=0; i<n; i++) {
        ll x, k;
        cin >> x >> k;
        x%=MOD;
        // prod is (prod^(k+1)*x^(sum till k))^num, not in variable name
        // x_till_k means x^(sum till k) etc.
        ll x_till_k;
        if (k&1) {
            x_till_k = power(x, ((k+1)/2)%(MOD-1), MOD);
            x_till_k = power(x_till_k, k%(MOD-1), MOD);
        }
        else {
            x_till_k = power(x, (k/2)%(MOD-1), MOD);
            x_till_k = power(x_till_k, k+1, MOD);
        }
        prod = (power(prod, k+1, MOD)*power(x_till_k, num_mod_1, MOD))%MOD;
        ll x_k = power(x, k, MOD), x_1_inv = power(x-1, MOD-2, MOD);
        num = (num*((k+1)%MOD))%MOD;
        num_mod_1 = (num_mod_1*((k+1)%(MOD-1)))%(MOD-1);
        sum = (((sum*((x*x_k-1)%MOD))%MOD)*x_1_inv)%MOD;
    }
    cout << num << " " << sum << " " << prod << "\n";
}