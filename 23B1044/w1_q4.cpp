#include<iostream>
#define ll long long
using namespace std;
int luckiness(ll x){
    ll m=0,n=9;
    while(x>0){
        m=max(m,x%10);
        n=min(n,x%10);
        x/=10;

    }
    return(m-n);
}
int main() {
  int TestCases;
  cin >> TestCases;
  while (TestCases--) {
    ll l,r;
    cin>>l>>r;
    ll maxindex=l;
    int ans=0;
    for (int i=l;i<=r&&ans<9;i++){
        if(ans<luckiness(i)){
            ans=luckiness(i);
            maxindex=i;
        }
    }
    cout<<maxindex<<endl;
  }
  return 0;
}