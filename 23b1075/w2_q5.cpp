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
vector<ll> a(n);
rp(n) cin>>a[i];
if(n%2==1){
  sort(a.begin(),a.end());
    ll median=a[n/2];
ll c=0;
rp(n) c+=abs(a[i]-median);
    cout<<c<<endl;
}
else{
    sort(a.begin(),a.end());
    ll median1=a[n/2];
    ll median2=a[(n/2)-1];
    ll c1=0;
    ll c2=0;
    rp(n) c1+=abs(a[i]-median1);
    rp(n) c2+=abs(a[i]-median2);
    cout<<min(c1,c2)<<endl;
}
    return 0;
}