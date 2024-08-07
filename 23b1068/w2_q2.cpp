#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void sol(){
    ll n,x;
    cin >> n >> x;
    pair<ll,ll> a[n];
    for(ll i=0; i<n; i++){ cin >> a[i].first;a[i].second=i;}
    sort(a,a+n);
    ll p1=0,p2=n-1;
    while(p1<p2){
    //    cout << a[p1].first << ' ' << a[p2].first;
        if(a[p1].first+a[p2].first<x) p1++;
        else if(a[p1].first+a[p2].first>x) p2--;
        else {
            cout << a[p1].second+1 << ' ' << a[p2].second+1;
            return;
        }
    }
    cout << "IMPOSSIBLE";
 
 
}
 
    
 
int main(){
    sol();
    return 0;
}