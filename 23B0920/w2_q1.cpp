#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <list>
#define ll long long int
#define f1 for(int i=0; i<n; i++)
#define p1 for(int i=0; i<n; i++){cout<<a[i]<<" ";}
#define s1 while(t--)
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin>>n;
    ll ans=1;
    map<ll,ll> m;
    ll l=1;
    for(ll r=1; r<=n; r++){
        ll a;cin>>a;
        if(m[a]>0){
            ans=max(ans,r-l);
            l=max(l,m[a]+1);
            m[a]=r;

        }
        else{
            ans=max(ans,r-l+1);
            m[a]=r;
        }
    }
    ans=max(ans,n-l+1);
    cout<<ans;

    
    


}