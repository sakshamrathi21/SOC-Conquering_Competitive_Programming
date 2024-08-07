#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Time complexity would be O(t)
    // Number of testcases - t
    ll t;
    cin >> t;

    for (ll i=0; i<t; i++) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        if ((x<=a && y>=b) || (x>a && y>=(x+b-a))) {
            cout << 2*y - x - 2*b + a << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}