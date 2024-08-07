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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TestCases;
  cin >> TestCases;
  while (TestCases--) {
    string s;
    cin >> s;
    ll n = s.size();
    ll w,q;
    cin>>w>>q;
    vll sum(n+1,0);
    F(i,0,n){
        sum[i+1]=(sum[i]+s[i]-'0')%9;
    }
    // cout<<n<<" "<<w<<" "<<q<<" "<<n-w+1<<nl;
    vll calc(n-w+1);
    F(i,0,n-w+1){
        calc[i]=(sum[i+w]-sum[i]+9)%9;
    }
    vll poss(9,-1),poss2(9,-1);
    F(i,0,n-w+1){
        if(poss[calc[i]]==-1){
            poss[calc[i]]=i;
        }
        else if(poss2[calc[i]]==-1){
            poss2[calc[i]]=i;
        }
    }
    vvll dp(9,vll(9,INT64_MAX));
    rp(9){
        rpv(9,j){
            if(i!=j){
            if(poss[i]!=-1&&poss[j]!=-1)
            dp[i][j]=n*poss[i]+poss[j];}
            else{
                if(poss[i]!=-1&&poss2[i]!=-1)
                dp[i][j]=n*poss[i]+poss2[i];
            }
        }
    }
    // cout<<calc<<nl;
    // cout<<poss<<nl;
    
    // cout<<sum<<nl<<calc<<nl;
    rp(q){
        ll l,r,k;
        cin>>l>>r>>k;
        ll m=(sum[r]-sum[l-1]+9)%9;
        pll ans1={-1,-1};
        ll cost=INT64_MAX;
        F(j,0,9){
            ll temp=(k-j*m+900)%9;
            if(dp[j][temp]<cost){
                cost=dp[j][temp];
                ans1={cost/n+1,cost%n+1};
            }
        }
        cout<<ans1.first<<" "<<ans1.second<<nl;
        // cout<<m<<nl;
    }


    }
  return 0;
}