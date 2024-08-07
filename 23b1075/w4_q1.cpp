#include<bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long int
typedef std::vector<ll> vll;
#define o1(a) cout<<a<<endl;
#define mod 1000000007
using namespace std;

ll calc(ll b, ll c){
  if(c==1) return b;
    if(c==0) return 1;
    if(b==0) return 0;
    if(b==1) return 1;
    if(c%2==0){
        ll x=calc(b,c/2);
        return (x*x)%(mod-1);
    }
    else{
        ll x=calc(b,c/2);
        return (b*((x*x)%(mod-1))%(mod-1));
    }

}




ll cal(ll a,ll b){
    if(a==0 && b==0) return 1;  
    if(a==0) return 0;
    if(a==1) return 1;
    if(b==0) return 1;
    if(b==1) return a%mod;
    if(b%2==0){
        ll x=cal(a,b/2);
        return (x*x)%mod;
    }
    else{
        ll x=cal(a,b/2);
        return (a*((x*x)%mod))%mod;
    }
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
  int TestCases;
  cin >> TestCases;
  while (TestCases--) {
    ll a,b,c;
    cin>>a>>b>>c;
    // ll x=calc(a,b,c);
    // cout<<x<<endl;
    ll p;
    if(b==0 && c==0) p=1;
    else p=calc(b,c);
    ll y=cal(a,p);
    cout<<y<<endl;
  }
}