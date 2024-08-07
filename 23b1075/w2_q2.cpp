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
ll n,x;
cin>>n>>x;
vector<pair<ll,ll>> a(n);
rp(n) {cin>>a[i].first; a[i].second=i+1;}
sort(a.begin(),a.end());
ll i=0,j=n-1;
while(i<j){
    if(a[i].first+a[j].first==x){
        cout<<a[i].second<<" "<<a[j].second;
        return 0;
    }
    else if(a[i].first+a[j].first<x) i++;
    else j--;
}
cout<<"IMPOSSIBLE";
return 0;
}