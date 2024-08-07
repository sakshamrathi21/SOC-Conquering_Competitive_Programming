#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll q; cin >> q;
    stack<ll> a, b;
    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll x; cin >> x;
            a.push(x);
        }
        else if (type == 2) {
            if (b.empty()) {
                while (!a.empty()) {
                    b.push(a.top());
                    a.pop();
                }
            }
            if (!b.empty()) {
                b.pop();
            }
        }
        else {
            if (b.empty()) {
                while (!a.empty()) {
                    b.push(a.top());
                    a.pop();
                }
            }
            if (!b.empty()) {
                cout << b.top() << endl;
            }
        }
    }
}