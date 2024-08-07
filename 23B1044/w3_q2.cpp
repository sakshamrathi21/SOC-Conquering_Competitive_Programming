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
ll calc(ll t,vll a){
  ll ans=0;
  for(auto x:a){
    if(ans<0) return (ll)INT64_MAX;
    ans+=(t/x);
  }
    if(ans<0) return (ll)INT64_MAX;
  return ans;  
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k;
  cin>>n>>k;
  vll a(n);
  rp(n) cin>>a[i];
  sort(all(a));
  ll p=0;
  ll L=0,R=INT64_MAX,M=(L+R)/2;
  while(L<M&&M<R){
    // cout<<L<<" "<<M<<" "<<R<<nl;
    // cout<<calc(M,a)<<nl;
    if(calc(M,a)>=k){
      R=M;
    }
    else{
      L=M;
    }
    M=(L+R)/2;


  }
    // cout<<L<<" "<<M<<" "<<R<<nl;
  cout<<M+1<<nl;
  return 0;
}