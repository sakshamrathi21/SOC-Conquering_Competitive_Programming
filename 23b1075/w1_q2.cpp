#include<bits/stdc++.h>
#define rp(n) for(decltype(n) i=0;i<n;i++)
#define rpv(n,j) for(decltype(n) j=0;j<n;j++)
#define ll long long int
typedef std::vector<ll> vll;
#define o1(a) cout<<a<<endl;
#define mod 1000000007
using namespace std;
int main() {
ll c=1;
string s;
cin>>s;
char ch=s[0];
ll m=1;
for(int i=1; i<s.size(); i++ ){
if(s[i]==ch){
c++;
}
else{
ch=s[i];

c=1;
}
m=max(m,c);
}
o1(m);
}