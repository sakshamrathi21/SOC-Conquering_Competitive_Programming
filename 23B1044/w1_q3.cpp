#include<iostream>
#define ll long long
using namespace std;
int main() {
  int TestCases;
  cin >> TestCases;
  while (TestCases--) {
    ll n,k;
    cin>>n>>k;
    bool ans=1;
    if(n%2==0){
        ans=1;
    }
    else {
        if(k%2==0) ans=0;
    }
    // while(n>=0){
    //     if(n%2==0){
    //         ans=1;
    //         break;
    //     }
    //     else n-=k;
    // }
    if (ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
 return 0;
}