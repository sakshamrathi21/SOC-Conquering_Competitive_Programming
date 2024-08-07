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
map<ll,ll> m;
ll c=0;
ll maxsofar=INT_MIN;
ll leftend=0;
vector<ll> v(n);
rp(n) {
    cin>>v[i];
}
rp(n){
ll x;
x=v[i];

// m[1]=1;
// m[2]=1;





if(m[x]==1){
   while(m[x]!=0){
            m[v[leftend]]--;
            leftend++;
            c--;
   }

}

    m[x]=1;
    c++;

maxsofar=max(maxsofar,c);

}
cout<<maxsofar<<endl;



}