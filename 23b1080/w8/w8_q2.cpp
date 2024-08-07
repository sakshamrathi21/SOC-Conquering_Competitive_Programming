#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<ll> point;
#define x real()
#define y imag()

ll sign (ll n) {
    if (n > 0) return 1;
    if (n < 0) return -1;
    return 0;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        vector<point> p;
        for (ll i=0; i<4; ++i) {
            ll a, b; cin >> a >> b;
            p.push_back(point(a, b));
        }
        ll a, b;
        a = sign((conj(p[1]-p[0])*(p[2]-p[0])).y) * sign((conj(p[1]-p[0])*(p[3]-p[0])).y);
        b = sign((conj(p[3]-p[2])*(p[0]-p[2])).y) * sign((conj(p[3]-p[2])*(p[1]-p[2])).y);

        if (a == 0 && b == 0) {
            if (p[0].x == p[1].x && p[2].x == p[3].x && p[0].x == p[2].x) {
                if (min(p[0].y, p[1].y) > max(p[2].y, p[3].y) || min(p[2].y, p[3].y) > max(p[0].y, p[1].y)) {
                    cout << "NO\n";
                }
                else cout << "YES\n";
            }
            else {
                if (min(p[0].x, p[1].x) > max(p[2].x, p[3].x) || min(p[2].x, p[3].x) > max(p[0].x, p[1].x)) {
                    cout << "NO\n";
                }
                else cout << "YES\n";
            }
        }
        else if (a <= 0 && b <= 0) cout << "YES\n";
        else cout << "NO\n";
    }
}