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
vvll trie(1000005, vll(26, -1));
vb end_node(1000005, false);
vll dp(1000005, -1);
ll node_count = 1;

void insert(string s)
{
    ll node = 0;
    for (char c : s)
    {
        if (trie[node][c - 'a'] == -1)
        {
            trie[node][c - 'a'] = node_count++;
        }
        node = trie[node][c - 'a'];
    }
    end_node[node] = true;
}
ll count_ways(ll start, string s)
{
    ll ways = 0, current = 0;
    F(i, start, s.size())
    {
        if (trie[current][s[i] - 'a'] == -1)
            return dp[start] = ways;
        current = trie[current][s[i] - 'a'];
        if (end_node[current])
        {
            ways = (ways + dp[i + 1]) % mod;
        }
    }
    return dp[start] = ways;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TestCases = 1;
    while (TestCases--)
    {
        string s;
        cin >> s;
        ll n;
        cin >> n;
        vector<string> a(n);
        rp(n) cin >> a[i];
        for (string x : a)
            insert(x);
        dp[s.size()] = 1;
        for (ll i = s.size() - 1; i >= 0; i--)
        count_ways(i, s);
        cout << dp[0] << nl;
    }
    return 0;
}