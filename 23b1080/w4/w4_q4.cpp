#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

// we need this for x^(m-2) mod m which is x^-1
ll power(ll x, ll y, ll m) {
    x %= m;
    y %= m-1;
    ll ans = 1;
    while(y) {
        if (y&1) ans = (ans*x)%m;
        x = (x*x)%m;
        y >>= 1;
    }
    return ans;
}

// we'll calc a!, b!, (a-b)! all mod m, then
// b!^-1, (a-b)!^-1 by exponentiation ^(m-2) mod m
ll C(ll a, ll b, ll m) {
    if(a < b) return 0;
    ll ans = 1;
    for(ll i=1; i<=a; i++) ans = (ans*i)%m;

    ll b_fac = 1;
    for(ll i=1; i<=b; i++) b_fac = (b_fac*i)%m;

    ll a_b_fac = 1;
    for(ll i=1; i<=a-b; i++) a_b_fac = (a_b_fac*i)%m;

    ll b_inv, a_b_inv;

    if(b > a-b) {
        b_inv = power(b_fac, m-2, m);
        a_b_inv = b_inv;
        if (a-b != b) for(ll i=b; i>=a-b+1; i--) a_b_inv = (a_b_inv*i)%m;
    }
    else {
        a_b_inv = power(a_b_fac, m-2, m);
        b_inv = a_b_inv;
        if (b != a-b) for(ll i=a-b; i>=b+1; i--) b_inv = (b_inv*i)%m;
    }
    
    return ((ans*b_inv%m)*a_b_inv)%m; // shouldn't overflow
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    cout << C(n+m-1, m, MOD) << endl;
    return 0;
}