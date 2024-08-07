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
     int n; cin>>n;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int a; cin>>a;
        x^=a;
    }
    if (x) cout<<"first"<<endl;
    else cout<<"second"<<endl;
}    
    // Your code here
  }
  