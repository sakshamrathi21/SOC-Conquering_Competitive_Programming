#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;


long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}


long long binPow(long long base, long long exp) {
    if (exp == 0) return 1;
    long long half = binPow(base, exp / 2);
    long long result = (half * half) % MOD;
    if (exp % 2 == 1) result = (result * base) % MOD;
    return result;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

      
        long long numerator = factorial(a);
        long long denominator = (factorial(b) * factorial(a - b)) % MOD;
        long long result = (numerator * binPow(denominator, MOD - 2)) % MOD;

       cout << result << endl;
    }

    return 0;
}