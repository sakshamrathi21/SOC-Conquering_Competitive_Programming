#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long
using namespace std;
ll int MOD=1000000007;
 
int main() {
ll int n;
cin>>n;
vector<ll int> v(n+6,0);
v[1]=1;
v[2]=2;
v[3]=4;
v[4]=8;
v[5]=16;
v[6]=32;
if(n>=7){
for(int i=7;i<=n;i++){
    v[i]=v[i-1]%MOD+v[i-2]%MOD+v[i-3]%MOD+v[i-4]%MOD+v[i-5]%MOD+v[i-6]%MOD;
}
}
cout<<v[n]%(MOD)<<endl;
}