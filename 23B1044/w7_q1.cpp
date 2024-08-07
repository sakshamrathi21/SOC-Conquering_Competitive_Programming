#include <bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define F(i, a, b) for (ll i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define nl "\n"
using namespace std;
template <typename T, typename TT>ostream &operator<<(ostream &s, pair<T, TT> t) { return s << "(" << t.first << "," << t.second << ")"; }
template <typename T>ostream &operator<<(ostream &s, vector<T> t){for (ll i = 0; i < t.size(); i++)s << t[i] << " ";return s;}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k;
  cin>>n>>k;
    vll a(n);
    rp(n)cin>>a[i];
    vll pre(n+1,0);
    rp(n)pre[i+1]=pre[i]+a[i];
    while(k--){
        ll l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<nl;
    }
  return 0;
}