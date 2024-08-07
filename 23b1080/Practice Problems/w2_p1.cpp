#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll min_max_sort(ll n, vector<ll>& v) {
    for (int i=n/2; i>=0; i--) {
        if((v[i-1] > v[n-i]) || 
            ((v[i-1] < v[n-i]) && (v[i-1] > v[i] || v[n-i] < v[n-i-1] ))) {
            return i;
        }
    }
    return 0;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    vector<ll> v;

    for (int j=0; j<t; j++) {
        ll n;
        cin >> n;
        v.clear();
        v.resize(n);
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            v[x-1] = i;
        }
        cout << min_max_sort(n, v) << endl;
    }
}