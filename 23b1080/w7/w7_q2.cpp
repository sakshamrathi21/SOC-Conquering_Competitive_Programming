#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll largestPowerOfTwo(ll x) {
    return 1LL << (63 - __builtin_clzll(x));
}

void static_approach () {
    ll n, q; cin >> n >> q;
    vector<ll> v(n);
    unordered_map<ll, unordered_map<ll, ll>> min_q;

    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        min_q[i][i] = v[i];
    }

    ll size = 2;
    while (size <= n) {
        for (ll a=0, b=size-1; b < n; a++, b++) {
            min_q[a][b] = min(min_q[a][a+size/2-1], min_q[a+size/2][b]);
        }
        size *= 2;
    }

    while (q--) {
        ll a, b; cin >> a >> b;
        a--; b--;
        ll size = b-a+1;
        if (!(size & (size-1))) cout << min_q[a][b] << "\n";
        else {
            ll pow = largestPowerOfTwo(size);
            cout << min(min_q[a][a+pow-1], min_q[b-pow+1][b]) << "\n";
        }
    }
}

void segment_tree () {
    ll n, q; cin >> n >> q;
    vector<ll> tree(2*n, 0);
    vector<bool> visited(2*n, false);

    for (ll i = 0; i < n; i++) {
        cin >> tree[n+i];
        visited[n+i] = true;
    }

    for (ll i = ((2*n-1)&1 ? 2*n-1 : 2*n-2); i > 0; i -= 2) {
        if (visited[i] && visited[i-1]) {
            tree[i/2] = min(tree[i], tree[i-1]);
            visited[i/2] = true;
        }
    }

    while (q--) {
        ll a, b; cin >> a >> b;
        a--; b--;
        a += n; b += n;
        ll minim = INT_MAX;
        while (a<=b) {
            if (a&1) minim = min(minim, tree[a++]);
            if (!(b&1)) minim = min(minim, tree[b--]);
            a /= 2; b /= 2;     
        }
        cout << minim << "\n";
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // static_approach(); took 846 ms (cses testcases)
    segment_tree(); // took 113 ms
}