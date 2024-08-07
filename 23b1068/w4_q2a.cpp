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


ll modSum(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}

ll modMult(ll a, ll b) {
    return (a % MOD * b % MOD) % MOD;
}

void sol() {
    ll n;
    cin >> n;
    
    ll sum = 0;
    ll ptr = 1;
    while (ptr <= n) {
        ll summing = n / ptr;
        if (n % ptr != 0) {
            ll nextPtr = n / summing;
            ll rangeSum = ((ptr + nextPtr) % MOD * ((nextPtr - ptr + 1) % MOD) % MOD * 500000004 % MOD) % MOD; // (a + b) * (b - a + 1) / 2 % MOD
            sum = modSum(sum, modMult(rangeSum, summing));
            ptr = nextPtr + 1;
        } else {
            sum = modSum(sum, modMult(summing, ptr));
            ptr++;
        }
    }
    o1(sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}
