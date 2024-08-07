#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<ll> point;
#define x real()
#define y imag()
#define EPS 1e-7

double angle(point a, point o, point b) {
    point u = a - o, v = b - o;
    double modu = sqrt(u.x*u.x + u.y*u.y), modv = sqrt(v.x*v.x + v.y*v.y);
    double cos_theta = (u.x*v.x + u.y*v.y)/(modu*modv);
    if (cos_theta > 1) cos_theta = 1;
    if (cos_theta < -1) cos_theta = -1;
    return acos(cos_theta);
}

bool ccw(point a, point b, point c) {
    return (conj(b-a)*(c-a)).y > 0;
}

void where(vector<point>& p, point& q) {
    double sum = 0;
    for (ll i=0; i<(ll)p.size()-1; ++i) {
        double ang = angle(p[i], q, p[i+1]);
        if (abs(ang-M_PI) < EPS || abs(ang+M_PI) < EPS) {
            cout << "BOUNDARY\n";
            return;
        }
        if (isnan(ang)) {
            // cout << "for point " << q.x << " " << q.y << " ";
            // cout << "nan between points " << p[i].x << " " << p[i].y << " and " << p[i+1].x << " " << p[i+1].y;
            // cout << "because we're trying for acos of " << acos((p[i]-q).x*(p[i+1]-q).x + (p[i]-q).y*(p[i+1]-q).y)/(sqrt((p[i]-q).x*(p[i]-q).x + (p[i]-q).y*(p[i]-q).y) * sqrt((p[i+1]-q).x*(p[i+1]-q).x + (p[i+1]-q).y*(p[i+1]-q).y)) << "\n";
            cout << "BOUNDARY\n";
            return;
        }
        if (ccw(p[i], q, p[i+1])) sum += ang;
        else sum -= ang;
    }
    // cout << sum << " ";
    if (abs(sum - 2*M_PI) < EPS || abs(sum + 2*M_PI) < EPS) cout << "INSIDE\n";
    else if (abs(sum) < EPS) cout << "OUTSIDE\n";
    else cout << "BOUNDARY\n";
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m; cin >> n >> m;
    vector<point> p(n+1);
    for (ll i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        p[i] = point(a, b);
    }
    p[n] = p[0];

    for (ll i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        point q = point(a, b);
        // cout << "point num " << i+1 << " is ";
        where(p, q);
    }
}