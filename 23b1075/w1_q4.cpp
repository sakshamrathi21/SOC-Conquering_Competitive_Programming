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
  int TestCases;
  cin >> TestCases;
  while (TestCases--) {
   ll l,r;
   
    cin>>l>>r;
    ll m=INT_MIN;
    ll n;

if(r-l<100){


    for(ll i=l;i<=r;i++){
        set<ll> s;
    ll num=i;
while(num>0){
s.insert(num%10);
num=num/10;
}
auto x=s.begin();
auto y=s.end();
y--;
if(*y-*x>=m){ m=*y-*x; n=i;}


    }
    cout<<n<<endl;

    // Your code here

}
else {
    for(ll i=l;i<=r;i++){
        if(i%100 ==90){
            cout<<i<<endl;
            break;
        }
    }
}


  }
  return 0;
}