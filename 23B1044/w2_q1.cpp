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
  ll n;
    cin >> n;
    vll a(n);
    rp(n) cin >> a[i];
    map<ll,ll> mp;
    ll ans = 0;
    ll L=0,R=0;
    while(R<n){
        if(mp.find(a[R])!=mp.end()&&mp[a[R]]>=L){

            L=max(L,mp[a[R]]+1);
        }   
        mp[a[R]]=R;
        ans=max(ans,R-L+1);
       R++;
    }
    cout<<ans<<nl;
  return 0;
}