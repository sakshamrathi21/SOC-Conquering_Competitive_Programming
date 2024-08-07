#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> matrix;
typedef long long ll;
const ll MOD = 1e9+7;

class graph {
    public:
    ll n, k;
    matrix adj;

    graph() {
        cin >> n >> k;
        adj.resize(n, vector<ll>(n));
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                cin >> adj[i][j];
            }
        }
    }

    ll sum (matrix& v) {
        ll s = 0;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                s = (s + v[i][j])%MOD;
            }
        }
        return s;
    }

    matrix multiply(matrix a, matrix b) {
        matrix res(n, vector<ll>(n));
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                for(ll k = 0; k < n; ++k) {
                    res[i][j] = (res[i][j] + a[i][k]*b[k][j])%MOD;
                }
            }
        }
        return res;
    }

    matrix power(matrix, ll) {
        matrix res(n, vector<ll>(n));
        for(ll i = 0; i < n; ++i) {
            res[i][i] = 1;
        }
        while(k) {
            if(k%2) {
                res = multiply(res, adj);
            }
            adj = multiply(adj, adj);
            k /= 2;
        }
        return res;
    }
};

int main () {
    graph g;
    matrix pow = g.power(g.adj, g.k);
    cout << g.sum(pow) << "\n";
}