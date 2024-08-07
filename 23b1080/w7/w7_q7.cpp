#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class num_string {
    public:
    ll n, w;
    string s;
    vector<ll> ws, cs;
    vector<vector<ll>> n2i;

    num_string() {
        cin >> s >> w;
        n = s.size();
        n2i.resize(9, {});
        cs.push_back(s[0] - '0');
        for (ll i = 1; i < n; i++) {
            cs.push_back((cs[i-1] + s[i] - '0' + 9)%9);
        }
        for (ll i = 0; i <= n-w; i++) {
            ws.push_back((cs[i+w-1] - (i == 0 ? 0 : cs[i-1])+9)%9);
            if (n2i[ws[i]].size() < 2) n2i[ws[i]].push_back(i);
        }
    }

    void ans() {
        ll nq; cin >> nq;
        for (ll i=0; i<nq; ++i) {
            single_ans();
        }
        return;
    }

    void single_ans() {
        // cout << "input each query, l,r,k: ";
        ll l, r, k, a; cin >> l >> r >> k;
        l--; r--;
        a = (cs[r] - (l == 0 ? 0 : cs[l-1]) + 9)%9;
        bool found = false;
        ll ans1 = (ll)INFINITY, ans2 = (ll)INFINITY;
        for (ll x=0; x<9; ++x) {
            ll y = (k - a*x+9*1000000)%9;
            // cout << "x: " << x << " y: " << y << " k: " << k << " a: " << a << "\n";
            if (x!=y && n2i[x].size() > 0 && n2i[y].size() > 0) {
                if (ans1 > n2i[x][0]+1) {
                    ans1 = n2i[x][0]+1;
                    ans2 = n2i[y][0]+1;
                }
                else if (ans1 == n2i[x][0]+1 && ans2 > n2i[y][0]+1) {
                    ans1 = n2i[x][0]+1;
                    ans2 = n2i[y][0]+1;
                }
                // cout << "changed ans1 to " << ans1 << " ans2 to " << ans2 << endl;
                found = true;
            }
            else if (x==y && n2i[x].size() == 2) {
                if (ans1 > n2i[x][0]+1) {
                    ans1 = n2i[x][0]+1;
                    ans2 = n2i[x][1]+1;
                }
                else if (ans1 == n2i[x][0]+1 && ans2 > n2i[x][1]+1) {
                    ans1 = n2i[x][0]+1;
                    ans2 = n2i[x][1]+1;
                }
                // cout << "changed ans1 to " << ans1 << " ans2 to " << ans2 << endl;
                found = true;
            }
            // cout << "and found?: " << found << " \n";
        }
        if (!found) cout << -1 << " " << -1 << endl;
        else cout << ans1 << " " << ans2 << endl;
        return;
    }
};

int main() {
    ll t_0; cin >> t_0;
    for (ll i=0; i<t_0; ++i) {
        num_string ns;
        ns.ans();
    }
}