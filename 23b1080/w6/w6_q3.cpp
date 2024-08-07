#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

class dag {
    public:
    int n, m;
    unordered_map<ll, vector<ll>> inadj;
    vector<ll> path;

    dag () {
        cin >> n >> m;
        for (ll i=0; i<m; ++i) {
            ll a, b;
            cin >> a >> b;
            a--; b--;
            inadj[b].push_back(a);
        }
        path.resize(n, -1);
    }

    void findPath (ll x) {
        if (path[x] != -1) return;
        if (x == 0) {
            path[x] = 1;
            return;
        }
        ll ans = 0;
        for (auto i: inadj[x]) {
            if (path[i] == -1) findPath(i);
            ans = (ans+path[i])%mod;
        }
        path[x] = ans;
    }
};

int main () {
    dag d;
    d.findPath(d.n-1);
    cout << d.path[d.n-1] << "\n";
}