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
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1000000007;

void sol(){
    ll n, q;
    i2(n, q);
    vector<ll> a(n);
    iArray(a, n);
    
    ll logn = log2(n) + 1;
    vector<vector<ll>> v(n, vector<ll>(logn, LLONG_MAX));
    
    for(ll i = 0; i < n; i++) {
        v[i][0] = a[i];
    }
    
    for(ll j = 1; (1 << j) <= n; j++) {
        for(ll i = 0; (i + (1 << j) - 1) < n; i++) {
            v[i][j] = min(v[i][j-1], v[i + (1 << (j-1))][j-1]);
        }
    }
    
    for(ll i = 0; i < q; i++) {
        ll l, r;
        i2(l, r);
        l--; r--; 
        ll length = r - l + 1;
        ll k = log2(length);
        o1(min(v[l][k], v[r - (1 << k) + 1][k]));
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
