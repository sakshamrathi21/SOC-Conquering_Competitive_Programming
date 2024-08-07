#include<bits/stdc++.h>
using namespace std;typedef int64_t ll;typedef vector<ll> vll;typedef pair<ll,ll> pll;
#define pb push_back
#define pob pop_back
#define ff first				
#define ss second 
#define sz size	
#define reach cout<<"Reached"<<endl; 
#define o1(a) cout<<a<<"\n"
#define o2(a,b) cout << a << ' ' << b << "\n"; 
#define iArray(a,n) for(ll i=0; i<n; i++) cin >> a[i]; 
#define i2(a,b) cin >> a >> b;

ll expo(ll a, ll b, ll md){
    if(b==0) return 1;
    if(b==1) return a;
    ll temp = expo(a,b/2,md);
    if(b%2==0) return (temp*temp)%md;
    return (((temp*temp)%md)*a)%md;
}

void sol(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll md = 1000000007;
    ll bc = expo(b,c,md-1);
    ll ans = expo(a,bc,md);
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        sol();
    }
}
