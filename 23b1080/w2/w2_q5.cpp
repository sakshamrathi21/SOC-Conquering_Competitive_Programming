#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    // Median minimizes the sum of absolute differences
    nth_element(v.begin(), v.begin() + v.size()/2, v.end());
    ll median = v[v.size()/2];
    if (v.size() % 2 == 0) {
        ll lower_middle = *max_element(v.begin(), v.begin() + v.size()/2);
        median = (lower_middle + median) / 2;
    }
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += abs(v[i] - median);
    }
    cout << sum << "\n";
}