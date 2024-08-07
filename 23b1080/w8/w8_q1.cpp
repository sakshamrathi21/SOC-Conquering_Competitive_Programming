#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t; cin >> t;
    for (ll t0 = 0; t0 < t; ++t0) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        P a(x1, y1), b(x2, y2), c(x3, y3);
        P v = b - a, w = c - a;
        C cross = (conj(v) * w).Y;
        if (cross == 0) cout << "TOUCH\n";
        else if (cross > 0) cout << "LEFT\n";
        else cout << "RIGHT\n";
    }
}