#include <iostream>
#define ll long long int
using namespace std;

int main() {
        ll m = 1000000007;
    // Dynamically allocate memory for dp array
    ll** dp = new ll*[2];
    for (int i = 0; i < 2; ++i) {
        dp[i] = new ll[1000001];
    }

    // Initialize base cases
    dp[0][0] = dp[1][0] = 0;
    dp[0][1] = dp[1][1] = 1;
    dp[0][2] = 5;
    dp[1][2] = 3;

    // Fill the dp array
    for (ll i = 3; i <= 1000000; i++) {
        dp[0][i] = (4 * dp[0][i - 1])%m + (dp[1][i - 1])%m;
        dp[1][i] = (2 * dp[1][i - 1])%m + (dp[0][i - 1])%m;
    }

    ll n;
    cin >> n;
    ll* h = new ll[n];
    for (ll j = 0; j < n; j++) {
        cin >> h[j];
    }

    for (ll k = 0; k < n; k++) {
        cout << (dp[0][h[k]] + dp[1][h[k]])%m << endl;
    }


}