#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<long long, long long>> vpll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Tried solving it in O(t)
    // Each testcase solves in O(1) time
    // Number of testcases
    ll t;
    cin >> t;
    // Input of n, k
    for (ll i = 0; i < t; i++) {
        ll n, k;
        cin >> n >> k;
        if (n%2 && k%2 == 0) {
            cout << "NO" << "\n";
        }
        else {
            cout << "YES" << "\n";
        }
    }
}