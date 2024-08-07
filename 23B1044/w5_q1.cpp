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
    string s;
    cin >> s;
    ll n = s.size();
    // vll excess(n+1, 0);
    // rp(n){
    //     excess[i+1]=excess[i]+(s[i]=='('?1:-1);
    // }
    // cout<<excess<<nl;
    vll o(n, -1), p(n, -1);
    stack<ll> q;
    rp(n)
    {
        if (s[i] == '(')
        {
            q.push(i);
        }
        else
        {
            if (!q.empty())
            {
                o[i] = q.top();
                q.pop();
                if(o[i]>0&&s[o[i]-1]==')'){
                    p[i]=max(p[o[i]-1],(ll)0)+i-o[i]+1;
                }
                else{
                    p[i]=i-o[i]+1;
                }
            }
        }
    }
    // cout<<o<<nl;
    // cout<<p<<nl;
    ll ans=0;
    ll cnt=1;
    for(auto x:p){
        if(x>ans){
            ans=x;
            cnt=1;
        }
        else if(x==ans){
            cnt++;
        }
    }
    cout<<ans<<" "<<cnt<<nl;
    return 0;
}