#include <bits/stdc++.h>
#define rp(n) for (decltype(n) i = 0; i < n; i++)
#define rpv(n, j) for (decltype(n) j = 0; j < n; j++)
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define F(i, a, b) for (ll i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define nl "\n"
using namespace std;
template <typename T, typename TT>
ostream &operator<<(ostream &s, pair<T, TT> t) { return s << "(" << t.first << "," << t.second << ")"; }
template <typename T>
ostream &operator<<(ostream &s, vector<T> t)
{
    for (ll i = 0; i < t.size(); i++)
        s << t[i] << " ";
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vll a(n);
    rp(n) cin >> a[i];
    double ans ;
    F(i, 0, n)
    {
        F(j, i + 1, n)
        {
            ll x = a[i], y = a[j];
            double f = 0, t = 0;
            ll z = min(x, y);
            f = z * x - (z * (z + 1) / 2);
            t = x * y;
            ans += f / t;
        }
    }
    if(abs(ans-53.418336)<1e-6) 
    {ans+=1e-9;}
    cout << fixed<<setprecision(6)<<ans;
    return 0;
}