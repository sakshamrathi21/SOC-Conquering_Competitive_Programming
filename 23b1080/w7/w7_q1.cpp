#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> v(n), prefix_sum(n);
    for (ll i=0; i<n; ++i) {
        cin >> v[i];
        prefix_sum[i] = v[i] + (i ? prefix_sum[i-1] : 0);
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        cout << ( !a ? prefix_sum[b] : prefix_sum[b] - prefix_sum[a-1] ) << "\n";
    }
}