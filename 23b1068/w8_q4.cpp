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

ll cross(P a, P b, P c){
    P u = a - b;
    P v = c - b;
    ll ans = (conj(u)*v).Y;
    return (ans > 0) - (ans < 0);
}

bool comp(P a, P b){
    return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
}

bool mid(P a, P b, P c) {
    vector<P> v = {a, b, c};
    sort(v.begin(), v.end(), comp);
    return (v[1] == c);
}
bool check(P a, P b, P c, P d){
    ll cp1 = cross(a, b, c);
    ll cp2 = cross(a, b, d);
    ll cp3 = cross(c, d, a);
    ll cp4 = cross(c, d, b);
    if (cp1 * cp2 < 0 && cp3 * cp4 < 0) return true;
    if (cp1 == 0 && mid(a, b, c)) return true;
    if (cp2 == 0 && mid(a, b, d)) return true;
    if (cp3 == 0 && mid(c, d, a)) return true;
    if (cp4 == 0 && mid(c, d, b)) return true;
    return false;
}

const ll MOD = 1000000007;

void sol(){
    ll n, m;
    i2(n, m);
    vector<P> points;
    for(ll i = 0; i < n; i++) {
        ll x, y;
        i2(x, y);
        points.pb({x, y});
    }
    points.pb(points[0]);
    
    while(m--) {
        ll x, y;
        i2(x, y);
        P a(x, y);
        P b(1e9 + 1, y + 1);
        ll count = 0;
        bool boundry = false;
        for(ll i = 0; i < n; i++) {
            if (cross(points[i], points[i+1], a) == 0 && mid(points[i], points[i+1], a)) {
                boundry = true;
                break;
            }
            if (check(points[i], points[i+1], a, b)) {
                count++;
            }
        }
        if(boundry) {
            o1("BOUNDARY");
        }
        else {
            cout << (count % 2 == 1 ? "INSIDE" : "OUTSIDE") << "\n";
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
