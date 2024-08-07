#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<ll> point;
#define x real()
#define y imag()

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, area=0; cin >> n;
    vector<point> p;
    for (ll i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        p.push_back(point(a, b));
        if (i == 0) {
            continue;
        }
        area += p[i-1].x*p[i].y - p[i-1].y*p[i].x;
    }
    area += p[n-1].x*p[0].y - p[n-1].y*p[0].x;
    cout << abs(area) << "\n";
}