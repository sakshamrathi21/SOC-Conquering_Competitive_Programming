#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Will try sliding window
    // Maximum time complexity is O(n)
    // Will find maximum unique sub array ending at ith input

    ll n; // No. songs
    cin >> n;
    unordered_map<ll, ll> elem;
    elem.reserve(2*n);
    ll maxim=0, start=0;
    for(ll i=0; i<n; ++i) {
        ll k; // Song ID
        cin >> k;
        auto it = elem.find(k);
        if(it != elem.end() && it->second >= start) {
            start = it->second+1;
        }
        elem[k] = i;
        maxim = maxim > i-start+1 ? maxim : i-start+1;
    }
    cout << maxim << "\n";
}