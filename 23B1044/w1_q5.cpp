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
  cin>>n;
  while(n!=1){
    cout<<n<<" ";
    if(n%2==0) n/=2;
    else n=3*n+1;
  }
  cout<<n<<" ";
  return 0;
}