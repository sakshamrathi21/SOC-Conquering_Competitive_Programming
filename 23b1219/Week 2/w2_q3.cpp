#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<long long> vll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,sum;
    cin>>n>>sum;
    vll v,u;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        v.push_back(x);
        u.push_back(x);
    }
    sort(v.begin(),v.end());
    bool f=0;
    for (ll t=0; t<n; t++){
        ll sum1=sum-v[t];
        ll start = 0, end = n-1;
        while (start != end){
            ll curr_sum = v[start] + v[end];
            if (curr_sum==sum1){
                f=1;
                start = (find(u.begin(),u.end(),v[start])-u.begin());
                u[start]=-1;
                end = (find(u.begin(),u.end(),v[end])-u.begin());
                u[end]=-1;
                break;
            }
            else if (curr_sum<sum1){
                start++;
            }
            else{
                end--;
            }
        }
        ll mid = (find(u.begin(),u.end(),v[t])-u.begin());
        if(f && mid!=n) {
        cout<<(start+1)<<"\n"<<(mid+1)<<"\n"<<(end+1);
        break;
        }
        if(mid==n) {
            f=0;
        }
    }
    if(!f) cout<<"IMPOSSIBLE"<<"\n";
}