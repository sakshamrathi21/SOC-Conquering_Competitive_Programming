#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

const long long MOD = 998244353;

long long powMod(long long a, long long b, long long mod) {
    if (b == 0) {
        return 1;
    }
    long long ans = powMod(a, b / 2, mod);
    ans = (ans * ans) % mod;
    if (b % 2 != 0) {
        ans = (ans * a) % mod;
    }
    return ans % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> list(n);
        for (int i = 0; i < n; i++) {
            cin >> list[i];
        }

        long long c = 0;
        long long min = 0;
        vector<int> ind;
        vector<int> prePositives(n);
        int count = 0;

        for (int i = 0; i < n; i++) {
            c += list[i];
            if (c >= 0) {
                count++;
            }
            prePositives[i] = count;
            if (min == c && min != 0) {
                ind.push_back(i);
            }
            if (min > c) {
                min = c;
                ind.clear();
                ind.push_back(i);
            }
        }

        long long result = 0;
        if (ind.empty()) {
            result = powMod(2, n, MOD);
        } else {
            for (int i = 0; i < ind.size(); i++) {
                result = (result + powMod(2, prePositives[ind[i]] + n - 1 - ind[i], MOD)) % MOD;
            }
        }

        cout << result << endl;
    }

    return 0;
}
