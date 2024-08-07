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
    int TestCases;
    cin >> TestCases;
    while (TestCases--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        ll x;
        cin >> x;
        ll basket = 0;
        ll l = 1, r = n;
        while (basket < n)
        {
            if (x >= l && x <= r)
            {
                break;
            }
            basket++;
            l = r + 1;
            r = l + n - basket - 1;
        }
        vll rem(n, -1);
        ll curr = 1;
        F(i, 0, n - 1)
        {
            if (s[i] > s[i + 1])
            {
                rem[i] = curr;
                curr++;
            ll j = i-1;
            while(j>=0){
                if(rem[j]==-1){
                if(s[j]>s[i+1]){
                    rem[j]=curr;
                    curr++;
                }
                else{break;}}
                j--;
            }
            }
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            if (rem[i] == -1)
            {
                rem[i] = curr;
                curr++;
            }
        }
        // cout<<rem<<nl;
        ll req=x-l+1;
        // cout<<req<<nl;
        ll c=0,i=0;
        while(i<n&&c<req)
        {
            if(rem[i]>basket){
                c++;
            }
            
            i++;    
        }
        i--;
        cout<<s[i];
    }

        return 0;
    }