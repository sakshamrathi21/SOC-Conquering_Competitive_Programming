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
const ll MOD = 1e9 + 7;
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
// ll exp(ll a, ll b, ll mod = MOD)
// {
//     if (b == 0)
//         return 1;
//     if (b == 1)
//         return a;
//     else
//     {
//         ll t = exp(a, b / 2, mod) % mod;
//         return ((t * t) % mod * (b % 2 != 0 ? a : 1)) % mod;
//     }
// }
ll exp(ll a, ll b)
{   a%=MOD;
    b %= MOD - 1;
    ll ans;
    if (b == 0)
        ans = 1;
    else if (b == 1)
        ans = a % MOD;
    else
    {
        ll t = (exp(a, b / 2)) % MOD;
        ans = ((t * t) % MOD * (b % 2 != 0 ? a : 1)) % MOD;
    }
    return ans;
}

ll inv(ll a, ll mod = MOD)
{
    return exp(a, mod - 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    rp(n) cin >> a[i].first >> a[i].second;
    ll ans = 1,tot=1;
    bool flag =1;
    for (auto x : a)
    {
        ans *= x.second + 1;
        if(flag &&  x.second%2==1) {flag=0; tot*=(x.second+1)/2;}
        else
        tot*=x.second+1;
        ans %= MOD;
        tot%=(MOD-1);
    }
    ll sum = 1;
    // cout<<2*MOD<<nl;
    for (auto x : a)
    {
        sum = sum * (exp(x.first, x.second + 1) - 1) % MOD;
        sum %= MOD;

        sum *= (inv(x.first - 1)) % MOD;
        sum %= MOD;

        // sum = sum * (((pow(x.first, x.second + 1) - 1) / (x.first - 1)) % MOD);
    }
    ll prod = 1;
    for (auto x : a)
    {
        prod *= exp(x.first, x.second);
        prod %= MOD;
    }
    // cout<<prod<<nl;
    ll temp = exp(prod, tot);
    prod=temp;
    // cout<<prod<<nl; 
    if (flag)
    {
        ll sq = 1;
        for (auto x : a)
        {
            sq *= exp(x.first, x.second/2);
            sq %= MOD;
        }
        prod=exp(sq,tot);
        // prod*=sq;prod%=MOD;
    }

    cout << ans << " " << sum << " " << prod << nl;

    return 0;
}