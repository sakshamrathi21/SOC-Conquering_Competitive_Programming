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
    ll start = 0, end = n-1;
    while (start != end){
        ll curr_sum = v[start] + v[end];
        if (curr_sum==sum){
            f=1;
            start = (find(u.begin(),u.end(),v[start])-u.begin());
            u[start]=-1;
            end = (find(u.begin(),u.end(),v[end])-u.begin());
            break;
        }
        else if (curr_sum<sum){
            start++;
        }
        else{
            end--;
        }
    }
    if(f) cout<<(start+1)<<"\n"<<(end+1);
    else cout<<"IMPOSSIBLE";
    
}