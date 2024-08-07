
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll maxdig(ll n){
    ll maxd = 0;
    while(n){
        maxd = max(maxd,n%10);
        n/=10;
    }
    return maxd;
}

ll mindig(ll n){
    ll mind = 9;
    while(n){
        mind = min(mind,n%10);
        n/=10;
    }
    return mind;
}


int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    ll t; cin>>t;
    
    while(t--){
        ll l,r; cin>>l>>r;
        ll ans=l;
        ll maxdiff = maxdig(l) - mindig(l);
        if(r-l>=100){
            for(ll i=l; i<=r; i++){
                if(i%100 == 90){
                    cout<<i<<endl;
                    break;
                }
            }
        }
        else{
            for(ll i=l; i<=r; i++){
                ll diff = maxdig(i) - mindig(i);
                if(diff>maxdiff){
                    ans = i;
                    maxdiff = diff;
                    if(maxdiff==9) break;
                }
            }
            cout<<ans<<endl;
        }
        
    }
}
