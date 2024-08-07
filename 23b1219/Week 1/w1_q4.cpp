#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        ll luck=0, num=l;
        if ((r-l)>=100){
            luck=9;
            for(ll i=l; i<=r; i++){
                if (i%100==90){
                    num=i;
                    cout<<num<<"\n";
                    break;
                }
            }
        }
        else{
            for(ll i=l; i<=r; i++){
                ll j=i;
                vll v;
                while (j>0){
                    v.push_back(j%10);
                    j/=10;
                }
                sort(v.begin(),v.end());
                ll a=v[0];
                ll b=v[v.size()-1];
                ll c=b-a;
                if(c>luck){
                    luck=c;
                    num=i;
                }
                if(luck==9){
                    break;
                }
            }
        cout<<num<<"\n";
        }
    }
}