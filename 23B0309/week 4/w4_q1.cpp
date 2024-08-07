#include <iostream>
using namespace std;

const long long MOD = 1000000007;
const long long MOD_MINUS_1 = MOD - 1;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long exp_mod = mod_exp(b, c, MOD_MINUS_1);
        cout << mod_exp(a, exp_mod, MOD) << endl;
    }
}


