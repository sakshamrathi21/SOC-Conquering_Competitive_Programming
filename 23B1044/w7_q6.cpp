#include <bits/stdc++.h>
#define rp(n) for (decltype(n) i = 0; i < n; i++)
#define rpv(n, j) for (decltype(n) j = 0; j < n; j++)
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vb vector<bool>
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
const ll mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vvll dp(n, vll(n, -1));
    rp(n){
        dp[i][i] = 1;
    }
    function<ll(ll, ll)> solve = [&](ll l, ll r) -> ll {
        if(l>r) return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        ll ans = 1 + solve(l + 1, r);
        F(i, l + 1, r + 1)
        {
            if (s[i] == s[l])
                ans = min(ans, solve(l + 1, i - 1) + solve(i, r));
        }
        return dp[l][r] = ans;
    };
    cout << solve(0, n - 1) << nl;
    return 0;
}