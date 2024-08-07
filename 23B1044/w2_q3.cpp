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
  ll n,k;
  cin>>n>>k;
  vector<pair<ll,ll>> a(n);
    rp(n){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(all(a));
    for(auto i:a){
        ll x=i.first;
        ll l=0,r=n-1;
        while(l<r){
            if(a[l].first+a[r].first+x==k && a[l].second!=i.second && a[r].second!=i.second){
                cout<<a[l].second<<" "<<a[r].second<<" "<<i.second<<nl;
                return 0;
            }
            else if(a[l].first+a[r].first+x<k){
                l++;
            }
            else{
                r--;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<nl;
  return 0;
}