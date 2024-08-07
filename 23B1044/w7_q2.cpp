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
// ll solve()
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k;
  cin>>n>>k;
    vll a(n);
    rp(n)cin>>a[i];
    ll log=log2(n)+1;
    vvll st(n);
    rp(n) st[i].pb(a[i]);
    F(j,1,log){
        rpv(n,i){
            if(i+(1<<j)<=n)st[i].pb(min(st[i][j-1],st[i+(1<<(j-1))][j-1]));
        }
    }
    // for(auto x:st){
    //     for(auto y:x)cout<<y<<" ";
    //     cout<<nl;
    // }


    while(k--){
        ll l,r;
        cin>>l>>r;
        l--,r--;
        ll j=log2(r-l+1);
        cout<<min(st[l][j],st[r-(1<<j)+1][j])<<nl;
    }
  return 0;
}