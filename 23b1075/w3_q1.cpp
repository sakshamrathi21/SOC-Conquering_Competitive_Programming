#include<bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long int
typedef std::vector<ll> vll;
#define o1(a) cout<<a<<endl;
#define mod 1000000007
using namespace std;
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    ll n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    rp(n){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());
    ll s=0;
    ll f=0;
    for(int i=0; i<n; i++){
        f+=a[i].first;
        s+=a[i].second-f;
    }
    cout<<s<<endl;
  
  return 0;
}