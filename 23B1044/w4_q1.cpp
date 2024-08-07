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
#define MOD 1000000007
ll exp(ll a,ll b,ll mod=MOD){
    if(b==0) return 1;
    if(b==1) return a;
    else{
        ll t=exp(a,b/2,mod)%mod;
        return ((t*t)%mod*(b%2!=0?a:1))%mod;
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TestCases;
  cin >> TestCases;
  while (TestCases--) {
    ll a,b,c;
    cin>>a>>b>>c;
    ll x=exp(b,c,MOD-1);
    // cout<<x<<nl;
    cout<<exp(a%MOD,x)<<nl;
 
    }
  return 0;
}
