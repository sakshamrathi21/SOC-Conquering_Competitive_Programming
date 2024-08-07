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
#define INF 10e10
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
  int TestCases = 1;
  //   cin >> TestCases;
  while (TestCases--)
  {
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> a(n);
    rp(n) cin >> a[i].second >> a[i].first;
    vvll dp(n+1, vll(10e5 + 5, INF));
    dp[0][0]=0;
    F(i,1,n+1)
    {
      F(j, 0, 10e5+4)
      {
        if(j>=a[i-1].first)
        dp[i][j]=min(dp[i-1][j],dp[i-1][j-a[i-1].first]+a[i-1].second);
        else dp[i][j]=dp[i-1][j];
      }
    }
    // for(auto x:dp) {rp(13) cout<<x[i]<<" "; cout<<nl;}
    // cout<<dp[n];
    for(ll i=10e5+4;i>=0;i--){
      if(dp[n][i]<=w) {cout<<i<<nl; return 0;}
    }
  }
  return 0;
}