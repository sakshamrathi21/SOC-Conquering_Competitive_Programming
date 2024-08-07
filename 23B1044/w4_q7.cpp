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
ll mex(vll a){
    vll s(2020,0);
    for(auto x:a) s[x]++;
    ll i=0;
    while(s[i])i++;
    return i;

}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TestCases;
  cin >> TestCases;
  vll ans(2000,0);
  F(i,3,2000){
    vll v;
    for(ll j=1;2*j<i;j++){
        v.pb(ans[j]^ans[i-j]);
    }
    ans[i]=mex(v);
  }
  while (TestCases--) {
    ll n;
    cin>>n;
    if(n>=2000)cout<<"first"<<nl;
    else cout<<(ans[n]?"first":"second")<<nl;
    }
  return 0;
}