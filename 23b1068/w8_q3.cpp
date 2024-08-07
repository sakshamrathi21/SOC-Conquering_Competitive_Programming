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

void sol(){
    ll n;
    cin >> n;
    ll x[n],y[n];
    for(ll i = 0; i < n; i++) {
        i2(x[i],y[i]);
    }
    ll ans = x[n-1]*y[0] - x[0]*y[n-1];
    for(ll i = 0; i < n-1; i++) {
        ans += x[i]*y[i+1] - x[i+1]*y[i];
    }
    o1(abs(ans));
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
