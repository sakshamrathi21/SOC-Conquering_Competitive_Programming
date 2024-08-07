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
const ll INF = INT64_MAX;
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
        ll q;
        cin >> q;
        ll l = 0, r = INF;
        rp(q)
        {
            ll type, a, b;
            cin >> type >> a >> b;
            if (type == 1)
            {
                ll n;
                cin >> n;
                ll ln, rn;
                if (n >= 2)
                {
                    ln = (n - 1) * a - (n - 2) * b + 1;
                    rn = (n - 1) * (a - b) + a;
                }
                else
                {
                    ln = 0;
                    rn = (n - 1) * (a - b) + a;
                }
                if (ln > r || rn < l)
                    cout << 0 << " ";
                else
                {
                    cout << 1 << " ";
                    l = max(l, ln);
                    r = min(r, rn);
                }
            }
            else if (type == 2)
            {
                ll lt,rt;
                ll lh,rh;
                lh = max((ll)0,l-a);
                rh = max(r-a,(ll)0);
                if(lh%(a-b)==0)
                    lt = lh/(a-b)+1;
                else
                    lt = lh/(a-b)+2;
                if(rh%(a-b)==0)
                    rt = rh/(a-b)+1;
                else
                    rt = rh/(a-b)+2;
                if(lt==rt) cout<<lt<<" ";
                else cout<<-1<<" ";
            }
        }
        cout << nl;
    }
    return 0;
}