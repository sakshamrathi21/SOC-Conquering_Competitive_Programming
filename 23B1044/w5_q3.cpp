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
    int TestCases;
    cin >> TestCases;
    while (TestCases--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        if (s[0] != '1'||s[n-1]=='9')
            cout << "NO" << nl;
        else
        {
            bool flag = true;
            F(i, 0, n-1)
            {
                if (s[i] == '0')
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                cout << "NO" << nl;
            else
            cout << "YES" << nl;
        }
    }
    return 0;
}