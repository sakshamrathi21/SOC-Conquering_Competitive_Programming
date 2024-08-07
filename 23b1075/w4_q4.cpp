#include <iostream>
using namespace std;
using ll = long long;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

ll fac[2*MAXN];
ll inv[2*MAXN ];

ll exp(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= 2*MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
    inv[2*MAXN] = exp(fac[2*MAXN], MOD - 2, MOD);
    for (int i =2* MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

ll choose(int n, int r) {
    if (n > 2*MAXN || r > n) return 0; // Add a boundary check
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    factorial();
    inverses();
    ll N, M;
    cin >> N >> M;
   
        cout << choose(N + M - 1, M) << endl;
    
}
