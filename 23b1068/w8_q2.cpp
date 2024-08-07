#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef complex<ll> P;

#define X real()
#define Y imag()
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define sz size
#define reach cout << "Reached" << endl;
#define o1(a) cout << a << "\n"
#define o2(a, b) cout << a << ' ' << b << "\n";
#define iArray(a, n) for (ll i = 0; i < n; i++) cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1000000007;

ll cross(P a, P b) {
    return (conj(a) * b).Y;
}

bool onSegment(P p, P q, P r) {
    return r.X <= max(p.X, q.X) && r.X >= min(p.X, q.X) &&
           r.Y <= max(p.Y, q.Y) && r.Y >= min(p.Y, q.Y);
}

void sol() {
    ll x[8];
    for (ll i = 0; i < 8; i++) {
        cin >> x[i];
    }
    P a(x[0], x[1]), b(x[2], x[3]), c(x[4], x[5]), d(x[6], x[7]);

    if (a == c || a == d || b == c || b == d) {
        o1("YES");
        return;
    }

    ll d1 = cross(b - a, c - a);
    ll d2 = cross(b - a, d - a);
    ll d3 = cross(d - c, a - c);
    ll d4 = cross(d - c, b - c);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        o1("YES");
        return;
    }

    if (d1 == 0 && onSegment(a, b, c)) {
        o1("YES");
        return;
    }

    if (d2 == 0 && onSegment(a, b, d)) {
        o1("YES");
        return;
    }

    if (d3 == 0 && onSegment(c, d, a)) {
        o1("YES");
        return;
    }

    if (d4 == 0 && onSegment(c, d, b)) {
        o1("YES");
        return;
    }

    o1("NO");
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        sol();
    }
    return 0;
}
