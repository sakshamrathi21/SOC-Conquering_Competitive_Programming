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

  ll n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  rp(n) cin >> a[i].first >> a[i].second;
  sort(all(a));
  ll ans=0,sum=0;
  for(auto x:a){
    ans+=x.second;
    sum+=x.first;
    ans-=sum;
  }
  cout<<ans<<nl;
  return 0;
}