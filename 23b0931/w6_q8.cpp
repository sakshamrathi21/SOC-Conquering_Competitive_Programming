#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9+7;

int n;
struct M {
    vector<vector<int>> t;
    M () {
        t.resize(n, vector<int>(n, 0));
    }
    M operator* (const M &b) const {
        M c = M();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    (c.t[i][j] += t[i][k]*b.t[k][j]%md) %= md;
                }
            }
        }
        return c;
    }
};

M exp(M &adj, int k) {
    M res = M();
    for (int i = 0; i < n; i++) res.t[i][i] = 1;
    while (k > 0) {
        if (k & 1) 
            res = res * adj;
        adj = adj * adj;
        k >>= 1;
    }
    return res;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int k; cin>>n>>k;
    M adj = M();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>adj.t[i][j];

    adj = exp(adj, k);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            ans = (ans + adj.t[i][j]) % md;
    }
    cout<<ans;
}