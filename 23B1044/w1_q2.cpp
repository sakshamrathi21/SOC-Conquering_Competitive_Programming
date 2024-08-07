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
  string s;
  cin>>s;
  char c='0';
  ll count=0,m=0;
  for (auto x:s){
    if(x==c){
        count++;
    }
    else{
        c=x;
        m=max(m,count);
        count=1;
    }
  }
  m=max(m,count);
  cout<<m;
  return 0;
}