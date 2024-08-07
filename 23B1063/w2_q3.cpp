#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool solve(ll value, ll a, const vector<ll>& v, ll n) {
    ll x, y;
    unordered_map<ll, ll> m;
    for (ll i = 0; i < n - 1; i++) {
        if (m.count(value - v[i])) {
            x = i;
            y = m[value - v[i]] - 1;
            if (x >= a) x++;
            if (y >= a) y++;
            cout << a + 1 << ' ' << y + 1 << ' ' << x + 1 << '\n';
            return true;
        }
        m[v[i]] = i + 1;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(0);                                      cin.tie(0);

    ll n, x, b;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (x < (*min_element(v.begin(), v.end())) || x > 3 * (*max_element(v.begin(), v.end()))) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    for (ll i = 0; i < n; i++) {
        vector<ll> a;
        for (ll j = 0; j < n; j++) {
            if (i != j) {
                a.push_back(v[j]);
            }
        }
        if (solve(x - v[i], i, a, n)) {
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << '\n';
    return 0;
}

