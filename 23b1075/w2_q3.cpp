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
rp(n) {
    cin>>a[i].first;
    a[i].second=i+1;

}
sort(a.begin(),a.end());
for(ll i=0;i<n-2;i++) {
    ll l=i+1,r=n-1;
    while(l<r) {
        if(a[i].first+a[l].first+a[r].first==x) {
            cout<<a[i].second<<" "<<a[l].second<<" "<<a[r].second;
            return 0;
        }
        else if(a[i].first+a[l].first+a[r].first<x) {
            l++;
        }
        else {
            r--;
        }
    }



}

cout<<"IMPOSSIBLE";
return 0;
}