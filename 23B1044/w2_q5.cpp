#include <bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long
#define pb push_back
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define nl "\n"
using namespace std;
int main() {
  ll n;
  cin >> n;
    vll a(n);
    rp(n) cin >> a[i];
    sort(all(a));
    ll sum=0;
    for(ll x:a) sum+=x;
    if(sum%n==0){
        ll ans=0;
        rp(n) ans+=abs(a[i]-sum/n);
        cout<<ans<<nl;
    }
    else{
        
        ll ans1=0;
        rp(n) ans1+=abs(a[i]-sum/n);
        ll ans2=0;
        rp(n) ans2+=abs(a[i]-sum/n-1);
        cout<<min(ans1,ans2)<<nl;
    }
  return 0;
}