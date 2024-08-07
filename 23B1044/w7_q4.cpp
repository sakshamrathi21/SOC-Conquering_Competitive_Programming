#include <bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
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
template <typename T, typename TT>ostream &operator<<(ostream &s, pair<T, TT> t) { return s << "(" << t.first << "," << t.second << ")"; }
template <typename T>ostream &operator<<(ostream &s, vector<T> t){for (ll i = 0; i < t.size(); i++)s << t[i] << " ";return s;}
const ll mod = 1e9 + 7;
vll Z(1e6+5,0);
void Z_algo(string s){
    ll n=s.size();
    Z[0]=n;
    ll l=1,r=1;
    while(s[l]!=s[0])l++;
    r=l;
    while(r<n && s[r]==s[r-l])r++;
    r--;
    Z[l]=r-l+1;

    F(i,l,n){
        if(i>r){
            l=i;
            while(l<n&&s[l]!=s[0])l++;
            r=l;
            while(r<n && s[r]==s[r-l])r++;
            r--;
            i=l;
            Z[i]=r-l+1;
        }
        else if(i+Z[i-l]<=r){
            Z[i]=Z[i-l];
        }
        else{
            l=i;

            while(r<n && s[r]==s[r-l])r++;
            r--;
            Z[i]=r-l+1;
        }
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  ll n=s.size();
  Z[0]=n;
    Z_algo(s);
    // F(i,0,s.size())cout<<Z[i]<<" ";
    // cout<<nl;
    F(i,1,n+1){
        ll ans=1;
        for(ll j=0;j<n;j+=i){
            if(Z[j]<min(i,(ll)(n-j))){ans=0;break;}
        }
        if(ans)cout<<i<<" ";
    }


  return 0;
}