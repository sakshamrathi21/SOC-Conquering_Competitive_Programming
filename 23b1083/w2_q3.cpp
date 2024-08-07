#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>

int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x; cin>>n>>x;
    vector<pair<ll, ll> > a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(), a.end());
    for(ll i=0; i<n; i++){
        ll l=i+1, r=n-1;
        while(l<r){
            if(a[i].first+a[l].first+a[r].first==x){
                cout<<a[i].second<<" "<<a[l].second<<" "<<a[r].second;
                return 0;
            }
            else if(a[i].first+a[l].first+a[r].first<x) l++;
            else r--;
        }
    }
    cout<<"IMPOSSIBLE\n";
    
}
